//#include "Node.h"
//#include <stdio.h>
//#include <cstdlib>
//#include <iostream>
//#include <vector>
//#include <fstream>
//#include <string>
//#include "Network.h"
//#include <algorithm>
//#include <map>
//#include <climits>
//#include <cstring>
//#include <string>
//#include <cfloat>
//
//
//void evaluate(string testname, int numBatchesTest, int totRecordsTest, Network* mynet){
//
//    int totCorrect = 0;
//    int debugnumber = 0;
//    std::string str;
//    std::ifstream testfile(testname);
//    assert(testfile);
//
//    for (size_t i = 0; i < numBatchesTest; i++) {
//        int **records = new int *[BATCHSIZE];
//        float **values = new float *[BATCHSIZE];
//        int *sizes = new int[BATCHSIZE];
//        int *labels = new int[BATCHSIZE];
//        int nonzeros = 0;
//        int count = 0;
//        vector<string> list;
//        vector<string> value;
//        while (std::getline(testfile, str)) {
//            if (count >= BATCHSIZE)
//                break;
//            char *mystring = &str[0];
//            char *pch;
//            pch = strtok(mystring, ", ");
//            labels[count] = stoi(pch);
//            int track = 0;
//            list.clear();
//            value.clear();
//            while (pch != NULL) {
//                if (track % 2 == 1)
//                    list.push_back(pch);
//                else if (track % 2 == 0 & track != 0)
//                    value.push_back(pch);
//                track++;
//                pch = strtok(NULL, " :");
//            }
//            //			if (list.size() < 10)
//            //				continue;
//            nonzeros += list.size();
//            records[count] = new int[list.size()];
//            values[count] = new float[value.size()];
//            sizes[count] = list.size();
//            int currcount = 0;
//            vector<string>::iterator it;
//            for (it = list.begin(); it < list.end(); it++) {
//                records[count][currcount] = stoi(*it);
//                currcount++;
//            }
//            currcount = 0;
//            for (it = value.begin(); it < value.end(); it++) {
//                values[count][currcount] = stof(*it);
//                currcount++;
//            }
//            count++;
//        }
//        auto t1 = std::chrono::high_resolution_clock::now();
//        auto correctPredict = mynet->predictClass(records, values, sizes, labels, BATCHSIZE);
//        auto t2 = std::chrono::high_resolution_clock::now();
//        int timeDiffInMiliseconds = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
//        std::cout << "each point takes" << 1.0 * timeDiffInMiliseconds << std::endl;
//
//        totCorrect += correctPredict;
//
//        delete[] sizes;
//        delete[] labels;
//        for (size_t d = 0; d < BATCHSIZE; d++) {
//            delete[] records[d];
//            delete[] values[d];
//        }
//        delete[] records;
//        delete[] values;
//
//    }
//    testfile.close();
//    cout << "over all " << totCorrect * 1.0 / totRecordsTest << endl;
//}
//
//
//
//int main()
//{
//
//    ofstream arrayData("model6/model.txt"); // File Creation(on C drive)
//    arrayData<<"hi"<<endl;
//
//    Timer *time = new Timer();
//
//    int totRecords = 45000000;
//    //13000000
//    //2625000
//    int totRecordsTest = 6000000;
//    int numBatches = totRecords/BATCHSIZE;
//    int numBatchesTest = totRecordsTest/BATCHSIZE;
//
//
//    //*************Testing***************
//    // Construct a fully connected network with 2 hidden layer
//    //***********************************
//
//    int * sizesOfLayers = new int[3];
//    NodeType* layersTypes = new NodeType[3];
//
//    sizesOfLayers[0] = 1000;
//    sizesOfLayers[1] = 1000;
//    sizesOfLayers[2] = 2;
//    layersTypes[0] = NodeType::ReLU;
//    layersTypes[1] = NodeType::ReLU;
//    layersTypes[2] = NodeType::Softmax;
//
//
//    Network* _mynet = new Network(sizesOfLayers, layersTypes, 3, 1000, time);
//    float minLogloss = FLT_MAX;
//    float lrFactor = 1.0;
//
//
//
//    for (int e=0; e< EPOCH; e++) {
//		std::ifstream file("/Users/beidchen/Documents/work/SUBLIME/HashingDeepLearning/bgd/criteo_sample");
//        string testname = "/Users/beidchen/Documents/work/SUBLIME/HashingDeepLearning/bgd/criteo_sample2";
//
////        std::ifstream file("/home/ec2-user/criteo/criteo.kaggle2014.train.svm");
////        string testname = "/home/ec2-user/criteo/criteo.kaggle2014.test.svm";
//
//
//        assert(file);
//        float accumlogss = 0;
//        std::string str;
//        bool rehash = false;
//
//        for (size_t i = 0; i < numBatches; i++) {
//            int **records = new int *[BATCHSIZE];
//            float **values = new float *[BATCHSIZE];
//            int *sizes = new int[BATCHSIZE];
//            int *labels = new int[BATCHSIZE];
//            int nonzeros = 0;
//            int count = 0;
//            vector<string> list;
//            vector<string> value;
//            while (std::getline(file, str)) {
//                if (count >= BATCHSIZE)
//                    break;
//                char *mystring = &str[0];
//                char *pch;
//                pch = strtok(mystring, ", ");
//                labels[count] = stoi(pch);
//                int track = 0;
//                list.clear();
//                value.clear();
//                while (pch != NULL) {
//                    if (track % 2 == 1)
//                        list.push_back(pch);
//                    else if (track % 2 == 0 & track != 0)
//                        value.push_back(pch);
//                    track++;
//                    pch = strtok(NULL, " :");
//                }
//                //			if (list.size() < 10)
//                //				continue;
//                nonzeros += list.size();
//                records[count] = new int[list.size()];
//                values[count] = new float[value.size()];
//                sizes[count] = list.size();
//                int currcount = 0;
//                vector<string>::iterator it;
//                for (it = list.begin(); it < list.end(); it++) {
//                    records[count][currcount] = stoi(*it);
//                    currcount++;
//                }
//                currcount = 0;
//                for (it = value.begin(); it < value.end(); it++) {
//                    values[count][currcount] = stof(*it);
//                    currcount++;
//                }
//                count++;
//            }
//
//            if (i%(REHASHING/BATCHSIZE)==(REHASHING/BATCHSIZE-1)){
//                rehash = true;
//            }
//            auto t1 = std::chrono::high_resolution_clock::now();
//            auto logloss = _mynet->ProcessInput(records, values, sizes, labels, BATCHSIZE, lrFactor, rehash, i);
//            auto t2 = std::chrono::high_resolution_clock::now();
//            int timeDiffInMiliseconds = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
//            std::cout << "each point takes" << 1.0 * timeDiffInMiliseconds << std::endl;
//
//
//
////            cout<< " wta takes "<< time->getWta() <<endl;
////            cout<< " lsh takes "<< time->getLsh() <<endl;
////            cout<< " backprop takes "<< time->getBackMul() <<endl;
////            cout<< " softmax takes "<< time->getForwardMul() <<endl;
////            cout<< " tableupdate takes "<< time->getTableUpdate() <<endl;
////            cout<< " sorting takes "<< time->getSort() <<endl;
//
//
//
//            accumlogss = logloss;
//            rehash = false;
//
//
//            delete[] sizes;
//            delete[] labels;
//            for (size_t d = 0; d < BATCHSIZE; d++) {
//                delete[] records[d];
//                delete[] values[d];
//            }
//            delete[] records;
//            delete[] values;
//
////            string testname = "/Users/beidchen/Documents/work/SUBLIME/HashingDeepLearning/bgd/q2bn/preproc_tst_1";
//
//
//            if ((i%STEPSIZE)==0)
//            {
//                cout<<"Step" <<i/STEPSIZE<<endl;
//                evaluate(testname, VALIDATION, BATCHSIZE*VALIDATION, _mynet);
//            }
//
//        }
//        std::cout << "Finished Epoch" << e << " Loss= " << accumlogss << endl;
//
//        file.close();
//
//        for (int layer = 0; layer< 3; layer++){
//            for (int id=0; id< _mynet->getLayer(layer)->_noOfNodes; id++){
//                arrayData<<_mynet->getLayer(layer)->getNodebyID(id)->_bias;
//                for (int dimen=0; dimen<_mynet->getLayer(layer)->getNodebyID(id)->_dim; dimen++){
//                    arrayData<<" "<<_mynet->getLayer(layer)->getNodebyID(id)->_weights[dimen];
//                }
//                arrayData<<endl;
//            }
//        }
//        evaluate(testname, numBatchesTest, BATCHSIZE*numBatchesTest, _mynet);
//    }
//    return 0;
//}










#include "Node.h"
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Network.h"
#include <algorithm>
#include <map>
#include <climits>
#include <cstring>
#include <string>
#include <cfloat>


void evaluate(string testname, int numBatchesTest, int totRecordsTest, Network* mynet){

    int totCorrect = 0;
    int debugnumber = 0;
    std::string str;
    std::ifstream testfile(testname);
    assert(testfile);

    for (size_t i = 0; i < numBatchesTest; i++) {
        int **records = new int *[BATCHSIZE];
        float **values = new float *[BATCHSIZE];
        int *sizes = new int[BATCHSIZE];
        int *labels = new int[BATCHSIZE];
        int nonzeros = 0;
        int count = 0;
        vector<string> list;
        vector<string> value;
        while (std::getline(testfile, str)) {
            char *mystring = &str[0];
            char *pch;
            pch = strtok(mystring, ", ");
            labels[count] = stoi(pch);
            int track = 0;
            list.clear();
            value.clear();
            while (pch != NULL) {
                if (track!=0){
                    list.push_back(pch);
                }
                pch = strtok(NULL, ", ");

                track++;
            }
            //			if (list.size() < 10)
            //				continue;
            nonzeros += list.size();
            records[count] = new int[list.size()];
            values[count] = new float[list.size()];
            if (list.size()!=value.size()){

            }

            sizes[count] = list.size();
            int currcount = 0;
            debugnumber++;
            vector<string>::iterator it;
            for (it = list.begin(); it < list.end(); it++) {
                records[count][currcount] = stoi(*it);
                values[count][currcount] = 1;
                currcount++;
            }
            count++;
            if (count >= BATCHSIZE)
                break;
        }
        auto t1 = std::chrono::high_resolution_clock::now();
        auto correctPredict = mynet->predictClass(records, values, sizes, labels, BATCHSIZE);
        auto t2 = std::chrono::high_resolution_clock::now();
        int timeDiffInMiliseconds = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
        std::cout << "each point takes" << 1.0 * timeDiffInMiliseconds << std::endl;

        totCorrect += correctPredict;

        delete[] sizes;
        delete[] labels;
        for (size_t d = 0; d < BATCHSIZE; d++) {
            delete[] records[d];
            delete[] values[d];
        }
        delete[] records;
        delete[] values;

    }
    testfile.close();
    cout << "over all " << totCorrect * 1.0 / totRecordsTest << endl;
}



int main()
{

    ofstream arrayData("model6/model.txt"); // File Creation(on C drive)
    arrayData<<"hi"<<endl;

    Timer *time = new Timer();

    int totRecords = 13000000;
    //
    //
    int totRecordsTest = 2625000;
    int numBatches = totRecords/BATCHSIZE;
    int numBatchesTest = totRecordsTest/BATCHSIZE;


    //*************Testing***************
    // Construct a fully connected network with 2 hidden layer
    //***********************************

    int * sizesOfLayers = new int[3];
    NodeType* layersTypes = new NodeType[3];

    sizesOfLayers[0] = 1000;
    sizesOfLayers[1] = 1000;
    sizesOfLayers[2] = 22427;
    layersTypes[0] = NodeType::ReLU;
    layersTypes[1] = NodeType::ReLU;
    layersTypes[2] = NodeType::Softmax;


    Network* _mynet = new Network(sizesOfLayers, layersTypes, 3, 1000, time);
    float minLogloss = FLT_MAX;
    float lrFactor = 1.0;



    for (int e=0; e< EPOCH; e++) {
//		std::ifstream file("/Users/beidchen/Documents/work/SUBLIME/HashingDeepLearning/bgd/q2bn/preproc_tst_0");
//        string testname = "/Users/beidchen/Documents/work/SUBLIME/HashingDeepLearning/bgd/q2bn/preproc_tst_1";

        std::ifstream file("/search_labs/users/beidchen/workspace/SUBLIME/HashingDeepLearning/bgd/q2bn/preproc_tr_0");
        string testname = "/search_labs/users/beidchen/workspace/SUBLIME/HashingDeepLearning/bgd/q2bn/preproc_tst_shuf_0";


        assert(file);
        float accumlogss = 0;
        std::string str;
        bool rehash = false;

        for (size_t i = 0; i < numBatches; i++) {
            int **records = new int *[BATCHSIZE];
            float **values = new float *[BATCHSIZE];
            int *sizes = new int[BATCHSIZE];
            int *labels = new int[BATCHSIZE];
            int nonzeros = 0;
            int count = 0;
            vector<string> list;
            vector<string> value;
            while (std::getline(file, str)) {

                char *mystring = &str[0];
                char *pch;
                pch = strtok(mystring, ", ");
                labels[count] = stoi(pch);
                int track = 0;
                list.clear();
                value.clear();
                while (pch != NULL) {
                    if (track != 0) {
                        list.push_back(pch);
                    }
                    pch = strtok(NULL, ", ");

                    track++;
                }
                nonzeros += list.size();
                records[count] = new int[list.size()];
                values[count] = new float[list.size()];
                sizes[count] = list.size();
                int currcount = 0;
                vector<string>::iterator it;
                for (it = list.begin(); it < list.end(); it++) {
                    records[count][currcount] = stoi(*it);
                    //cout<<records[count][currcount]<<endl;
                    values[count][currcount] = 1;
                    currcount++;
                }
                count++;
                if (count >= BATCHSIZE)
                    break;
            }

            if (i%(REHASHING/BATCHSIZE)==(REHASHING/BATCHSIZE-1)){
                rehash = true;
            }


            if ((i%STEPSIZE)==0)
            {
                cout<<"Step" <<i/STEPSIZE<<endl;
                evaluate(testname, VALIDATION, BATCHSIZE*VALIDATION, _mynet);
//                exit(0);
            }

            if ((i%(STEPSIZE*50))==(STEPSIZE*50-1))
            {
                cout<<"Big eval Step" <<i/(STEPSIZE*10)<<endl;
                evaluate(testname, VALIDATION*10, BATCHSIZE*VALIDATION*10, _mynet);
//                exit(0);
            }

            auto t1 = std::chrono::high_resolution_clock::now();
            auto logloss = _mynet->ProcessInput(records, values, sizes, labels, BATCHSIZE, lrFactor, rehash, e*numBatches+i);
            auto t2 = std::chrono::high_resolution_clock::now();
            int timeDiffInMiliseconds = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
            std::cout << i<<" each point takes" << 1.0 * timeDiffInMiliseconds << std::endl;



//            cout<< " wta takes "<< time->getWta() <<endl;
//            cout<< " lsh takes "<< time->getLsh() <<endl;
//            cout<< " backprop takes "<< time->getBackMul() <<endl;
//            cout<< " softmax takes "<< time->getForwardMul() <<endl;
//            cout<< " tableupdate takes "<< time->getTableUpdate() <<endl;
//            cout<< " sorting takes "<< time->getSort() <<endl;



            accumlogss = logloss;
            rehash = false;


            delete[] sizes;
            delete[] labels;
            for (size_t d = 0; d < BATCHSIZE; d++) {
                delete[] records[d];
                delete[] values[d];
            }
            delete[] records;
            delete[] values;



        }
        std::cout << "Finished Epoch" << e << " Loss= " << accumlogss << endl;

        file.close();

        for (int layer = 0; layer< 3; layer++){
            for (int id=0; id< _mynet->getLayer(layer)->_noOfNodes; id++){
                arrayData<<_mynet->getLayer(layer)->getNodebyID(id)->_bias;
                for (int dimen=0; dimen<_mynet->getLayer(layer)->getNodebyID(id)->_dim; dimen++){
                    arrayData<<" "<<_mynet->getLayer(layer)->getNodebyID(id)->_weights[dimen];
                }
                arrayData<<endl;
            }
        }


        evaluate(testname, numBatchesTest, BATCHSIZE*numBatchesTest, _mynet);

    }

    return 0;
}







//#include "Node.h"
//#include <stdio.h>
//#include <cstdlib>
//#include <iostream>
//#include <vector>
//#include <fstream>
//#include <string>
//#include "Network.h"
//#include <algorithm>
//#include <map>
//#include <climits>
//#include <cstring>
//#include <cfloat>
//
//#define ALL(c) c.begin(), c.end()
//#define FOR(i,c) for(typeof(c.begin())i=c.begin();i!=c.end();++i)
//#define REP(i,n) for(int i=0;i<n;++i)
//#define fst first
//#define snd second
//
//void endianSwap(unsigned int &x) {
//    x = (x>>24)|((x<<8)&0x00FF0000)|((x>>8)&0x0000FF00)|(x<<24);
//}
//typedef vector<unsigned int> Image;
//
//
//int main()
//{
//
//
//
//
//    Timer *time = new Timer();
//
//    cout<<"finish d reading"<<endl;
//    int totRecords = 60000;
//    int totRecordsTest = 10000;
//    int numBatches = totRecords/BATCHSIZE;
//    int numBatchesTest = totRecordsTest/BATCHSIZE;
//
//
//    //*************Testing***************
//    // Construct a fully connected network with 2 hidden layer
//    //***********************************
//
//    int * sizesOfLayers = new int[3];
//    NodeType* layersTypes = new NodeType[3];
//
//    sizesOfLayers[0] = 1000;
//    sizesOfLayers[1] = 500;
//    sizesOfLayers[2] = 10;
//    layersTypes[0] = NodeType::ReLU;
//    layersTypes[1] = NodeType::ReLU;
//    layersTypes[2] = NodeType::Softmax;
//
//
//    Network* _mynet = new Network(sizesOfLayers, layersTypes, 3, 1000, time);
//    float minLogloss = FLT_MAX;
//    float lrFactor = 1.0;
//    bool rehash = false;
//
//    for (int e=0; e< EPOCH; e++) {
//        float accumlogss = 0;
//        std::string str;
//        FILE *fimage = fopen("/Users/beidchen/Documents/work/SUBLIME/HashingDeepLearning/bgd/origin/train-images-idx3-ubyte", "rb");
//        FILE *flabel = fopen("/Users/beidchen/Documents/work/SUBLIME/HashingDeepLearning/bgd/origin/train-labels-idx1-ubyte", "rb");
//        assert(fimage);
//        assert(flabel);
//
//        unsigned int magic, num, row, col;
//        fread(&magic, 4, 1, fimage);
//        assert(magic == 0x03080000);
//        fread(&magic, 4, 1, flabel);
//        assert(magic == 0x01080000);
//
//        fread(&num, 4, 1, flabel); // dust
//        fread(&num, 4, 1, fimage); endianSwap(num);
//        fread(&row, 4, 1, fimage); endianSwap(row);
//        fread(&col, 4, 1, fimage); endianSwap(col);
//
//
//        FILE *fimaget = fopen("/Users/beidchen/Documents/work/SUBLIME/HashingDeepLearning/bgd/origin/t10k-images-idx3-ubyte", "rb");
//        FILE *flabelt = fopen("/Users/beidchen/Documents/work/SUBLIME/HashingDeepLearning/bgd/origin/t10k-labels-idx1-ubyte", "rb");
//        assert(fimaget);
//        assert(flabelt);
//
//        unsigned int magict, numt, rowt, colt;
//        fread(&magict, 4, 1, fimaget);
//        assert(magict == 0x03080000);
//        fread(&magict, 4, 1, flabelt);
//        assert(magict == 0x01080000);
//
//        fread(&numt, 4, 1, flabelt); // dust
//        fread(&numt, 4, 1, fimaget); endianSwap(numt);
//        fread(&rowt, 4, 1, fimaget); endianSwap(rowt);
//        fread(&colt, 4, 1, fimaget); endianSwap(colt);
//
//        for (size_t b = 0; b < numBatches; b++) {
//            int **records = new int *[BATCHSIZE];
//            float **values = new float *[BATCHSIZE];
//            int *sizes = new int[BATCHSIZE];
//            int *labels = new int[BATCHSIZE];
//            int nonzeros = 0;
//            int count = 0;
//            vector<int> list;
//            vector<float> value;
//
//            REP(k, BATCHSIZE) {
//                Image img(col * row);
//                REP(i, col) REP(j, row)
//                        fread(&img[i * row + j], 1, 1, fimage);
//                unsigned char label = 0;
//                fread(&label, 1, 1, flabel);
//                labels[k] = label;
//
//
//                list.clear();
//                value.clear();
//                count = 0;
//                REP(i, col) {
//                    REP(j, row){
//                        float tmp = img[i * row + j];
//                        if (tmp>0){
//                            list.push_back(i*row+j);
//                            value.push_back(tmp);
//                            count++;
//                        }
//
//                    }
//                }
//
//                sizes[k] = count;
//                records[k] = new int[list.size()];
//                values[k] = new float[list.size()];
//
//                int currcount = 0;
//                vector<int>::iterator it;
//                for (it = list.begin(); it < list.end(); it++) {
//                    records[k][currcount] = *it;
//                    currcount++;
//                }
//                currcount = 0;
//                vector<float>::iterator it2;
//                for (it2 = value.begin(); it2 < value.end(); it2++) {
//                    values[k][currcount] = *it2/255.0;
//                    currcount++;
//                }
//
//            }
//
//            auto t1 = std::chrono::high_resolution_clock::now();
//            if (b%(REHASHING/BATCHSIZE)==0){
//                rehash = true;
//            }
//            t1 = std::chrono::high_resolution_clock::now();
//            auto logloss = _mynet->ProcessInput(records, values, sizes, labels, BATCHSIZE, lrFactor, rehash, b);
//            rehash = false;
////            auto logloss = _mynet->ProcessInput(records, values, sizes, labels, BATCHSIZE, lrFactor);
//            auto t2 = std::chrono::high_resolution_clock::now();
//            int timeDiffInMiliseconds = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
//            std::cout << "each point takes" << 1.0 * timeDiffInMiliseconds << std::endl;
//            accumlogss=logloss;
//
//
//            if (accumlogss > minLogloss) {
//                lrFactor *= 1 - LRFACTOR;
//            } else {
//                lrFactor = 1 + LRFACTOR;
//                minLogloss = accumlogss;
//            }
//
//            delete[] sizes;
//            delete[] labels;
//            for (size_t d = 0; d < BATCHSIZE; d++) {
//                delete[] records[d];
//                delete[] values[d];
//            }
//            delete[] records;
//            delete[] values;
//
//
//        }
//        std::cout << "Finished Epoch" <<e<< " Loss= "<<accumlogss << endl;
//
//
//
//        int totCorrect = 0;
//        int debugnumber = 0;
//        for (size_t b = 0; b < numBatchesTest; b++) {
//            int **records = new int *[BATCHSIZE];
//            float **values = new float *[BATCHSIZE];
//            int *sizes = new int[BATCHSIZE];
//            int *labels = new int[BATCHSIZE];
//            int nonzeros = 0;
//            int count = 0;
//            vector<int> list;
//            vector<float> value;
//
//            REP(k, BATCHSIZE) {
//                Image img(colt * rowt);
//                REP(i, colt) REP(j, rowt)
//                        fread(&img[i * rowt + j], 1, 1, fimaget);
//                unsigned char label = 0;
//                fread(&label, 1, 1, flabelt);
//                labels[k] = label;
//
//
//                list.clear();
//                value.clear();
//                count = 0;
//                REP(i, colt) {
//                    REP(j, rowt){
//                        float tmp = img[i * rowt + j];
//                        if (tmp>0){
//                            list.push_back(i*rowt+j);
//                            value.push_back(tmp);
//                            count++;
//                        }
//
//                    }
//                }
//
//                sizes[k] = count;
//                records[k] = new int[list.size()];
//                values[k] = new float[list.size()];
//
//                int currcount = 0;
//                vector<int>::iterator it;
//                for (it = list.begin(); it < list.end(); it++) {
//                    records[k][currcount] = *it;
//                    currcount++;
//                }
//                currcount = 0;
//                vector<float>::iterator it2;
//                for (it2 = value.begin(); it2 < value.end(); it2++) {
//                    values[k][currcount] = *it2/255.0;
//                    currcount++;
//                }
//
//            }
////
//            auto correctPredict = _mynet->predictClass(records, values, sizes, labels, BATCHSIZE);
//            totCorrect += correctPredict;
//
////			std::cout << "Finished iteration " << i << " with " << correctPredict * 1.0 / BATCHSIZE << endl;
//
//            delete[] sizes;
//            delete[] labels;
//            for (size_t d = 0; d < BATCHSIZE; d++) {
//                delete[] records[d];
//                delete[] values[d];
//            }
//            delete[] records;
//            delete[] values;
//
//        }
//
//        cout << "over all " << totCorrect * 1.0 / totRecordsTest << endl;
//    }
//
//
//    return 0;
//
//}