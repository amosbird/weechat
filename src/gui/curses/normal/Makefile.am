#
# Copyright (C) 2003-2022 Sébastien Helleu <flashcode@flashtux.org>
#
# This file is part of WeeChat, the extensible chat client.
#
# WeeChat is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# WeeChat is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with WeeChat.  If not, see <https://www.gnu.org/licenses/>.
#

AM_CPPFLAGS = -DLOCALEDIR=\"$(datadir)/locale\" $(NCURSES_CFLAGS)

noinst_LIBRARIES = lib_weechat_gui_curses.a

lib_weechat_gui_curses_a_SOURCES = ../gui-curses-bar-window.c \
                                   ../gui-curses-chat.c \
                                   ../gui-curses-color.c \
                                   ../gui-curses-key.c \
                                   ../gui-curses-main.c \
                                   ../gui-curses-mouse.c \
                                   ../gui-curses-term.c \
                                   ../gui-curses-window.c \
                                   ../gui-curses.h

bin_PROGRAMS = weechat

# Due to circular references, we must link two times with libweechat_core.a
# (and with two different path/names to be kept by linker)
weechat_LDADD = ./../../../core/lib_weechat_core.a \
                ../../../plugins/lib_weechat_plugins.a \
                ../../lib_weechat_gui_common.a \
                lib_weechat_gui_curses.a \
                ../../../core/lib_weechat_core.a \
                $(PLUGINS_LFLAGS) \
                $(NCURSES_LFLAGS) \
                $(GCRYPT_LFLAGS) \
                $(GNUTLS_LFLAGS) \
                $(CURL_LFLAGS) \
                $(ZLIB_LFLAGS) \
                $(ZSTD_LFLAGS) \
                -lm

weechat_SOURCES = main.c

EXTRA_DIST = CMakeLists.txt

# Create a symbolic link weechat-curses -> weechat
# This link is created for compatibility with old versions on /upgrade.
# It may be removed in future.
install-exec-hook:
	(cd '$(DESTDIR)$(bindir)' && $(RM) weechat-curses$(EXEEXT) && $(LN_S) weechat weechat-curses$(EXEEXT))

# Remove symbolic link on uninstall
uninstall-hook:
	(cd '$(DESTDIR)$(bindir)' && $(RM) weechat-curses$(EXEEXT))
