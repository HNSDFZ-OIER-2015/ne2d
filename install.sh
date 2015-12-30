rm -rf /usr/include/ne2d/
mkdir /usr/include/ne2d/
mkdir /usr/include/ne2d/math/
mkdir /usr/include/ne2d/utility/
mkdir /usr/include/ne2d/raw/
mkdir /usr/include/ne2d/thirdparty/

cp ./release/libne2d.so /usr/lib/libne2d.so
cp ./src/*.hpp /usr/include/ne2d/
cp ./src/math/*.hpp /usr/include/ne2d/math/
cp ./src/utility/*.hpp /usr/include/ne2d/utility/
cp ./src/raw/*.hpp /usr/include/ne2d/raw/
cp -rf ./src/thirdparty/ /usr/include/ne2d/
