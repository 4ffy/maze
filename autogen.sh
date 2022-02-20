#!/bin/sh

aclocal
autoheader
automake -a
autoconf
automake -a

./configure $@
