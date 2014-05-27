# sqlite-enhanced-icu

## Goal

An extension to SQLite that add locale aware collations and custom functions into SQLite.

## Source

It's based on [these files](http://www.sqlite.org/src/tree?name=ext/icu) from SQLite sources. I used [this specific revision](http://www.sqlite.org/src/info/3eeb0ff78d04891b5fd1a3d99a9fb8cfbed77a81) as the latest revision was not working with Debian Wheezy.

## Features

TODO

## How to build

### Original documentation

Please check the original [README.txt](README.txt).

### Install dependancies

```bash
aptitude install libicu-dev libsqlite3-dev build-essential
```

### Build

```bash
gcc -shared icu.c `icu-config --ldflags` -fPIC -o libSqliteIcu.so
```

The flag `-fPIC` is only needed if you're using a 64bits kernel.

## LICENSE

The original file has no copyright at all. Only my additions are copyrighted.

Copyright 2013-2014 Sébastien Lucas

Released under GPL version 2 License.