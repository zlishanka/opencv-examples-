dirlist=$(find . -mindepth 1 -maxdepth 1 -type d)

for dir in $dirlist
do 
  (
  if [ $dir == "./.git" ]; then 
      continue
  fi 
  cd $dir
  echo $dir
  rm -rf CMakeCache.txt CMakeFiles cmake_install.cmake Makefile
  rm -rf build
  rm -rf lib 
  )
done
