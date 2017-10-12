find . -type f -exec sed -i "s|include \"ExRootAnalysis|include \"$(pwd)\/external\/ExRootAnalysis|g" {} \;
./configure; make
