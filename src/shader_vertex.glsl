#version 330 core
#define COW 8
#define PI 3.1415926
// Atributos de v�rtice recebidos como entrada ("in") pelo Vertex Shader.
// Veja a fun��o BuildTrianglesAndAddToVirtualScene() em "main.cpp".
layout (location = 0) in vec4 model_coefficients;
layout (location = 1) in vec4 normal_coefficients;
layout (location = 2) in vec2 texture_coefficients;

// Matrizes computadas no c�digo C++ e enviadas para a GPU
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform int object_id;
uniform vec4 bbox_min;
uniform vec4 bbox_max;
uniform sampler2D TextureImage7;

// Atributos de v�rtice que ser�o gerados como sa�da ("out") pelo Vertex Shader.
// ** Estes ser�o interpolados pelo rasterizador! ** gerando, assim, valores
// para cada fragmento, os quais ser�o recebidos como entrada pelo Fragment
// Shader. Veja o arquivo "shader_fragment.glsl".
out vec4 position_world;
out vec4 position_model;
out vec4 normal;
out vec2 texcoords;
out vec3 cowIllumination;

void main()
{
    // A vari�vel gl_Position define a posi��o final de cada v�rtice
    // OBRIGATORIAMENTE em "normalized device coordinates" (NDC), onde cada
    // coeficiente estar� entre -1 e 1 ap�s divis�o por w.
    // Veja {+NDC2+}.
    //
    // O c�digo em "main.cpp" define os v�rtices dos modelos em coordenadas
    // locais de cada modelo (array model_coefficients). Abaixo, utilizamos
    // opera��es de modelagem, defini��o da c�mera, e proje��o, para computar
    // as coordenadas finais em NDC (vari�vel gl_Position). Ap�s a execu��o
    // deste Vertex Shader, a placa de v�deo (GPU) far� a divis�o por W. Veja
    // slides 41-67 e 69-86 do documento Aula_09_Projecoes.pdf.

    gl_Position = projection * view * model * model_coefficients;

    // Como as vari�veis acima  (tipo vec4) s�o vetores com 4 coeficientes,
    // tamb�m � poss�vel acessar e modificar cada coeficiente de maneira
    // independente. Esses s�o indexados pelos nomes x, y, z, e w (nessa
    // ordem, isto �, 'x' � o primeiro coeficiente, 'y' � o segundo, ...):
    //
    //     gl_Position.x = model_coefficients.x;
    //     gl_Position.y = model_coefficients.y;
    //     gl_Position.z = model_coefficients.z;
    //     gl_Position.w = model_coefficients.w;
    //

    // Agora definimos outros atributos dos v�rtices que ser�o interpolados pelo
    // rasterizador para gerar atributos �nicos para cada fragmento gerado.

    // Posi��o do v�rtice atual no sistema de coordenadas global (World).
    position_world = model * model_coefficients;

    // Posi��o do v�rtice atual no sistema de coordenadas local do modelo.
    position_model = model_coefficients;

    // Normal do v�rtice atual no sistema de coordenadas global (World).
    // Veja slides 123-151 do documento Aula_07_Transformacoes_Geometricas_3D.pdf.
    normal = inverse(transpose(model)) * normal_coefficients;
    normal.w = 0.0;

    // Coordenadas de textura obtidas do arquivo OBJ (se existirem!)
    texcoords = texture_coefficients;

    if (object_id == COW){
         // Coordenadas de textura U e V
        float U = 0.0;
        float V = 0.0;

        vec4 bbox_center = (bbox_min + bbox_max) / 2.0;

        vec4 cowPosition = bbox_center + normalize(position_model - bbox_center);
        vec4 cowTexture = cowPosition - bbox_center;

        //Obtemos os �ngulos
        float teta = atan(cowTexture.x, cowTexture.z);
        float phi = asin(cowTexture.y);

        U = (teta + PI) / (2*PI);
        V = (phi + PI / 2) / PI;

        vec4 cameraOrigin = vec4(0.0, 0.0, 0.0, 1.0);
        vec4 camera_position = inverse(view) * cameraOrigin;
        vec4 p = position_world;
        vec4 n = normalize(normal);
        vec4 v = normalize(camera_position - p);
        vec4 l = v;
        vec4 h = normalize(v + l);

        vec3 Kd = texture(TextureImage7, vec2(U,V)).rgb;
        vec3 Ks = vec3(0.5, 0.5, 0.5);
        vec3 Ka = vec3(0.0, 0.0, 0.0);
        float q = 37.0;

        vec3 I = vec3(0.7, 0.7, 0.7);
        vec3 Ia = vec3(0.5, 0.5, 0.5);

        vec3 lambert_diffuse_term = Kd * I * max(0, dot(n, l));
        vec3 ambient_term = Ka * Ia;
        vec3 phong_specular_term  = Ks * I * pow(max(0, dot(n, h)), q);

        cowIllumination = lambert_diffuse_term + ambient_term + phong_specular_term;
        cowIllumination = pow(cowIllumination, vec3(1.0,1.0,1.0)/2.2);
    }
}

