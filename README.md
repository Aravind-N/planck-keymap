# JD40-keymap

This is a layout configuration for the JD40 keyboard

## Prep Work

Clone Wilba6582's fork of the tmk keyboard controller firmware into a directory of your choosing
```shell
$ cd YOUR_DIRECTORY
$ git clone https://github.com/Wilba6582/tmk_keyboard.git
```
Copy the jd40 directory to tmk
```shell
$ cp -r ./jd40 YOUR_DIRECTORY/keyboard
```

## Build Environment Setup (Taken from [Jack Humbert's QMK firmware](https://github.com/jackhumbert/qmk_firmware))

### Windows 10

It's still recommended to use the method for Vista and later below. The reason for this is that the Windows 10 Subsystem for Linux lacks [USB support](https://wpdev.uservoice.com/forums/266908-command-prompt-console-bash-on-ubuntu-on-windo/suggestions/13355724-unable-to-access-usb-devices-from-bash), so it's not possible to flash the firmware to the keyboard. Please add your vote to the link!

That said, it's still possible to use it for compilation. And recommended, if you need to compile much, since it's much faster than at least Cygwin (which is also supported, but currently lacking documentation). I haven't tried the method below, so I'm unable to tell.

Here are the steps

1. Install the Windows 10 subsystem for Linux, following [these instructions](http://www.howtogeek.com/249966/how-to-install-and-use-the-linux-bash-shell-on-windows-10/).
2. If you have previously cloned the repository using the normal Git bash, you will need to clean up the line endings. If you have cloned it after 20th of August 2016, you are likely fine. To clean up the line endings do the following
   1. Make sure that you have no changes you haven't committed by running `git status`, if you do commit them first
   2. From within the Git bash run `git rm --cached -r .`
   3. Followed by `git reset --hard`
3. Start the "Bash On Ubuntu On Windows" from the start menu
4. With the bash open, navigate to your Git checkout. The harddisk can be accessed from `/mnt` for example `/mnt/c` for the `c:\` drive.
5. Run `sudo util/install_dependencies.sh`.
6. After a while the installation will finish, and you are good to go

**Note** From time to time, the dependencies might change, so just run `install_dependencies.sh` again if things are not working.

**Warning:** If you edit Makefiles or shell scripts, make sure you are using an editor that saves the files with Unix line endings. Otherwise the compilation might not work.


### Windows (Vista and later)
1. If you have ever installed WinAVR, uninstall it.
2. Install [MHV AVR Tools](https://infernoembedded.com/sites/default/files/project/MHV_AVR_Tools_20131101.exe). Disable smatch, but **be sure to leave the option to add the tools to the PATH checked**.
3. If you are going to flash Infinity based keyboards you will need to install dfu-util, refer to the instructions by [Input Club](https://github.com/kiibohd/controller/wiki/Loading-DFU-Firmware).
4. Install [MinGW](https://sourceforge.net/projects/mingw/files/Installer/mingw-get-setup.exe/download). During installation, uncheck the option to install a graphical user interface. **DO NOT change the default installation folder.** The scripts depend on the default location.
5. Clone this repository. [This link will download it as a zip file, which you'll need to extract.](https://github.com/jackhumbert/qmk_firmware/archive/master.zip) Open the extracted folder in Windows Explorer.
6. Open the `\util` folder.
7. Double-click on the `1-setup-path-win` batch script to run it. You'll need to accept a User Account Control prompt. Press the spacebar to dismiss the success message in the command prompt that pops up.
8. Right-click on the `2-setup-environment-win` batch script, select "Run as administrator", and accept the User Account Control prompt. This part may take a couple of minutes, and you'll need to approve a driver installation, but once it finishes, your environment is complete!

If you have trouble and want to ask for help, it is useful to generate a *Win_Check_Output.txt* file by running `Win_Check.bat` in the `\util` folder.

### Mac
If you're using [homebrew,](http://brew.sh/) you can use the following commands:

    brew tap osx-cross/avr
    brew install avr-libc
    brew install dfu-programmer

This is the recommended method. If you don't have homebrew, [install it!](http://brew.sh/) It's very much worth it for anyone who works in the command line.

You can also try these instructions:

1. Install Xcode from the App Store.
2. Install the Command Line Tools from `Xcode->Preferences->Downloads`.
3. Install [DFU-Programmer][dfu-prog].

### Linux

To ensure you are always up to date, you can just run `sudo util/install_dependencies.sh`. That should always install all the dependencies needed.

You can also install things manually, but this documentation might not be always up to date with all requirements.

The current requirements are the following, but not all might be needed depending on what you do. Also note that some systems might not have all the dependencies available as packages, or they might be named differently.

```
build-essential
gcc
unzip
wget
zip
gcc-avr
binutils-avr
avr-libc
dfu-programmer
dfu-util
gcc-arm-none-eabi
binutils-arm-none-eabi
libnewlib-arm-none-eabi
git
```

Install the dependencies with your favorite package manager.

Debian/Ubuntu example:

    sudo apt-get update
    sudo apt-get install gcc unzip wget zip gcc-avr binutils-avr avr-libc dfu-programmer dfu-util gcc-arm-none-eabi binutils-arm-none-eabi libnewlib-arm-none-eabi

## Compiling

Navigate to the jd40 directory and then execute the following commands to build and flash the firmware to the keyboard's controller. This assumes you are using a dfu based method for flashing your device. If you are using some other method, these commands WILL NOT WORK for you

```shell
$ cd YOUR_DIRECTORY/tmk_keyboard/keyboard/jd40
$ make clean
$ make dfu
```

Congratulations, you now have built your own firmware for the JD40!
