rm -rf Delphes
git clone https://github.com/adarshp/delphes Delphes
# git clone https://github.com/delphes/delphes Delphes
cd Delphes
find . -type f -exec sed -i "s|include \"ExRootAnalysis|include \"$(pwd)\/external\/ExRootAnalysis|g" {} \;
./configure; make
cd ..
