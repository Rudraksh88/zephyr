# Zephyr

## Overview

Zephyr (meaning "breeze" in Greek) is a light wind that usually comes from the west. Zephyr is a fork of [BreezeEnhanced](https://github.com/tsujan/BreezeEnhanced) which itself is a fork of KDE Breeze.


![Preview](preview.png)

Zephyr is a minimal theme focused on simplicity and elegance.

### Features:
Better looking buttons and overall aesthetics with the same bells and whistles as BreezeEnhanced.

## Screenshots/Previews:
![Hover Preview](hover.gif)

## Why another fork?
Well I tried a lot of Kvantum themes and albeit they all looked beautiful, they were not as responsive as BreezeEnhanced (or any other native KDE theme). For example, sometimes the clicks would not register or if you clicked twice on the minimize/maximize button very quickly, the window would register both the clicks and minimize/maximize twice.

Other forks like [SierraBreezeEnhanced](https://github.com/kupiqu/SierraBreezeEnhanced) and others were perfectly fine but they had precise hitboxes and required you to click inside the button geometry to register a click. This was not the case with KDE Breeze and BreezeEnhanced. BreezeEnhanced was good but still, had very thin (non macOS style) icons for the buttons.

So I decided to fork BreezeEnhanced and fine-tune it to my liking.

## Installation
```
Tested on KDE Plasma 6.1.1
```

#### Same installation instructions as BreezeEnhanced:
The version number in the file [NEWS](NEWS) shows the main version of KWin that is required for the compilation. *Compilation should not be done against other versions of KWin!*

In what follows, it is supposed that the name of the installation directory of KDE libraries is `lib` and the installation prefix is `/usr`. If they are different in your distro, please replace them!

Open a terminal inside the source directory and do:
```sh
mkdir build && cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Release -DKDE_INSTALL_LIBDIR=lib -DBUILD_TESTING=OFF -DKDE_INSTALL_USE_QT_SYS_PATHS=ON
make
sudo make install
```
After the intallation, restart KWin by logging out and in. Then, BreezeEnhanced will appear in *System Settings &rarr; Application Style &rarr; Window Decorations*.

If you are using Wayland, you can just restart the compositor using
```sh
kwin_wayland --replace
```

## Known issues:
- The current version is still named BreezeEnhanced in the source code. I will change it in the future.
- Properly implemented only at Medium size. Other sizes are probably buggy.
- Only supports Dark theme for now. Light theme will be added in the future.

## Future plans:
I just quickly hacked the theme to my liking, just so I could use it. I will fix the issues and add more features in the future. Here are some of the things I plan to do:

- [ ] Add Light theme
- [ ] Add support for other sizes
- [ ] Move the hardcoded values for icon stroke, padding, etc. to the UI
- [ ] Add a monochrome macOS style
- [ ] Port other features from SierraBreezeEnhanced

## Credits:

BreezeEnhanced by [Pedram Pourang a.k.a Tsu Jan](https://github.com/tsujan/Kvantum/tree/master/Kvantum#contact)


BreezeEnhanced was started from [BreezeBlurred](https://github.com/alex47/BreezeBlurred), a former fork of Breeze with title-bar translucency and blurring.

Needless to say, the main work behind BreezeEnhanced is the Breeze KWin decoration itself, which can be downloaded from <https://download.kde.org/stable/plasma/>.