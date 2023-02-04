# Asteroids Re-make

A *work-in-progress*, practicing with object-oriented programming using `C++` and the `SFML` library to create a simple take on the classic arcade game **Asteroids** by game developer **Atari**.

## Installing dependencies

The game requires the SFML library to be installed and the path linked in the Makefile.

#### Using brew install

If you already have `brew` installed on your system, then you can skip this step.

If not, you can install brew using the following command:

```
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

#### Installing SFML using brew

on macOS or Linux command line run the following command:

```sh
brew install sfml
```

#### Installing SFML without brew

If you do not want to install brew, then you can install SFML from their website directly at:

https://www.sfml-dev.org/download.php

#### Linking the path in the Makefile

You will need to tell the Makefile where the SFML library is located.

To find where the SFML packages were installed:

```sh
brew info sfml
```

Replace the following line in the makefile with the `path` on your system

```makefile
LDIR=/usr/local/Cellar/sfml/2.5.1_2
```

## Running the project

Navigate to the `src` directory of the project files

```
cd src
```

Then execute the following command:

```
make
```

This will not only start the application but will also make an executable file in the bin directory and subsequent runs can be started by opening that file.

If the code is modified, you will need to run the command again to recompile the project.