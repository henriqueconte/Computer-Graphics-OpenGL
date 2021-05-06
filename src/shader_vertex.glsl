#version 330 core
#define COW 8
#define PI 3.1415926
// Atributos de vértice recebidos como entrada ("in") pelo Vertex Shader.
// Veja a função BuildTrianglesAndAddToVirtualScene() em "main.cpp".
layout (location = 0) in vec4 model_coefficients;
layout (location = 1) in vec4 normal_coefficients;
layout (location = 2) in vec2 texture_coefficients;

// Matrizes computadas no código C++ e enviadas para a GPU
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform int object_id;
uniform vec4 bbox_min;
uniform vec4 bbox_max;
uniform sampler2D TextureImage7;

// Atributos de vértice que serão gerados como saída ("out") pelo Vertex Shader.
// ** Estes serão interpolados pelo rasterizador! ** gerando, assim, valores
// para cada fragmento, os quais serão recebidos como entrada pelo Fragment
// Shader. Veja o arquivo "shader_fragment.glsl".
out vec4 position_world;
out vec4 position_model;
out vec4 normal;
out vec2 texcoords;
out vec3 cowIllumination;

void main()
{
    // A variável gl_Position define a posição final de cada vértice
    // OBRIGATORIAMENTE em "normalized device coordinates" (NDC), onde cada
    // coeficiente estará entre -1 e 1 após divisão por w.
    // Veja {+NDC2+}.
    //
    // O código em "main.cpp" define os vértices dos modelos em coordenadas
    // locais de cada modelo (array model_coefficients). Abaixo, utilizamos
    // operações de modelagem, definição da câmera, e projeção, para computar
    // as coordenadas finais em NDC (variável gl_Position). Após a execução
    // deste Vertex Shader, a placa de vídeo (GPU) fará a divisão por W. Veja
    // slides 41-67 e 69-86 do documento Aula_09_Projecoes.pdf.

    gl_Position = projection * view * model * model_coefficients;

    // Como as variáveis acima  (tipo vec4) são vetores com 4 coeficientes,
    // também é possível acessar e modificar cada coeficiente de maneira
    // independente. Esses são indexados pelos nomes x, y, z, e w (nessa
    // ordem, isto é, 'x' é o primeiro coeficiente, 'y' é o segundo, ...):
    //
    //     gl_Position.x = model_coefficients.x;
    //     gl_Position.y = model_coefficients.y;
    //     gl_Position.z = model_coefficients.z;
    //     gl_Position.w = model_coefficients.w;
    //

    // Agora definimos outros atributos dos vértices que serão interpolados pelo
    // rasterizador para gerar atributos únicos para cada fragmento gerado.

    // Posição do vértice atual no sistema de coordenadas global (World).
    position_world = model * model_coefficients;

    // Posição do vértice atual no sistema de coordenadas local do modelo.
    position_model = model_coefficients;

    // Normal do vértice atual no sistema de coordenadas global (World).
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

        //Obtemos os ângulos
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

