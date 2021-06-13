# Computer-Graphics-OpenGL

=== Windows
==================================
To compile and run this project on Windows, download IDE Code::Blocks from
http://codeblocks.org/ and open the file "Laboratorio_X.cbp".

**ATTENTION**: the default "Build targets" (Debug and Release) are configured
for Code::Blocks version 20.03 or higher, which uses 64-bit MinGW. If you
are using older versions of Code::Blocks (17.12 or earlier)
you need to change the "Build target" to "Debug (17.12 32-bit CBlocks)" or
"Release (17.12 32-bit CBlocks)" before compiling the project.

=== Linux
==================================
To compile and run this project on Linux, you first need to install
the necessary libraries. To do this, run the command below in a terminal.
This is usually sufficient on an Ubuntu Linux installation:

    sudo apt-get install build-essential make libx11-dev libxrandr-dev \
                         libxinerama-dev libxcursor-dev libxcb1-dev libxext-dev \
                         libxrender-dev libxfixes-dev libxau-dev libxdmcp-dev

If you use Linux Mint, you might need to install a few more libraries:

    sudo apt-get install libmesa-dev libxxf86vm-dev

After installing the above libraries, you have two options for compilation:
use Code::Blocks or Makefile.

--- Linux with Code::Blocks
-----------------------------------
Install the Code::Blocks IDE (Linux version at http://codeblocks.org/), open the
file "Laboratorio_X.cbp", and change the "Build target" from "Debug" to "Linux".

--- Linux with Makefile
-----------------------------------
Open a terminal, navigate to the folder "Laboratorio_0X_Codigo_Fonte", and run
the "make" command to compile. To run the compiled code, run the
"make run" command.

=== macOS
==================================
To compile and run this project on macOS, you first need to install
HOMEBREW, a package manager for easy library installation. O
HOMEBREW can be installed with the following command in the terminal:

    /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"

After installing HOMEBREW, the GLFW library must be installed. This can
be done by the terminal with the command:

    brew install glfw

--- macOS with Makefile
-----------------------------------
Open a terminal, navigate to the folder "Laboratorio_0X_Codigo_Fonte", and run
the command "make -f Makefile.macOS" to compile. To run the code
compiled, run the command "make -f Makefile.macOS run".

Note: The current version of the Code::Blocks IDE is quite outdated for the
macOS. The official developer note is: "Code::Blocks 17.12 for Mac is
currently not available due to the lack of Mac developers, or developers that
own a Mac. We could use an extra Mac developer (or two) to work on Mac
compatibility issues."

=== Troubleshooting
==================================

If you have problems running this project's code, try updating the
driver for your video card.
