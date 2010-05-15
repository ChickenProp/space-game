#ifndef _CONF_H
#define _CONF_H

#define DVORAK 1

#if DVORAK
#  define KEY_UP sf::Key::Comma
#  define KEY_DOWN sf::Key::O
#  define KEY_LEFT sf::Key::A
#  define KEY_RIGHT sf::Key::E
#else
#  define KEY_UP sf::Key::W
#  define KEY_DOWN sf::Key::S
#  define KEY_LEFT sf::Key::A
#  define KEY_RIGHT sf::Key::D
#endif

#endif
