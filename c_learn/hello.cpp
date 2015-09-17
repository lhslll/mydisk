#include "hello.h"
#include <fstream>
#include "IntArray.h"
#include "TArray.h"
#include <vector>
#include <algorithm>
#include <map>
#include <complex>
#include <utility>
#include "MyString.h"
#include <bitset>
#include <ctype.h>

using std::string;

template <typename T>
void myprint(T *begin, T *end)
{
        while(begin != end)
        {
                std::cout << *begin << std::endl;
                begin++;
        }
}

int getSize()
{
        return 3;
}

typedef int* intp;


int& TestFun(int &a)
{
        a++;
        return a;
}

int& TestFun2(int *a)
{
        (*a)++;
        return *a;
}





using namespace std;
typedef pair<short,short> location;
typedef vector<location> loc;
typedef vector<string> text;
typedef pair<text*, loc*> text_loc;


void filter_text(vector<string> *words, string filter)
{
        if(!filter.size())
        {
                filter = "\",.";
        }

        for(vector<string>::iterator begin = words->begin(); begin != words->end(); begin++)
        {
                string::size_type pos =0;
                while((pos = (*begin).find_first_of(filter, pos))!= string::npos)
                {
                        (*begin).erase(pos, 1);
                }
        }
}


void word_caps(vector<string> *words)
{
        string::size_type pos =0;
        string capString = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for(vector<string>::iterator iter = words->begin();
            iter != words->end(); iter++)
        {
                while((pos = (*iter).find_first_of(capString, pos))!= string::npos)
                {
                        (*iter)[pos] = tolower((*iter)[pos]);

                }

        }

}


extern std::vector<string>* loadfileText();
extern text_loc* separate_words(std::vector<string>* textlines);

template <typename T,int size>
T min(T (&array)[size])
{
        return array[0];
}

typedef int (&rai)[10];
typedef double (&rad)[10];

void funt( int (*)(rai));


int main()
{
        int arr1[10];
        double arr2[20];

        min(arr1);
        min(arr2);

        funt(static_cast<int (*)(rai)>(&min));



        int* buf = new int[sizeof(int)*10];

        int* test1 = new (buf)int(1);
        int* test2 = new (buf)int(2);


        delete [] buf;

        delete test1;



        multimap<string, string> mmap;
        mmap.insert( multimap<string,string>::value_type("lhs", "abc"));
        mmap.insert(multimap<string,string>::value_type("lhs", "ac)"));


        int ssssize = mmap.count("lhs");

        multimap<string,string>::iterator iterss =  mmap.find("lhs");

        while(iterss != mmap.end())

        {
                cout<< iterss->first << endl;
                cout << iterss->second << endl;
                iterss++;
        }


        return 0;

        vector<string> *wordss = new vector<string>;

        wordss->push_back("huLHenABg\",a..bc");


        word_caps(wordss);
        filter_text(wordss,"");

        return 0;




        std::vector<string> *textp = loadfileText();


        text_loc *t_loc = separate_words(textp);

        return 0;

        std::vector<string> fsv;
        fsv.push_back("lhs");


        std::vector<string>::iterator fsvfind;
        fsvfind =  std::find(fsv.begin(),fsv.end(),"lhs2");

        if(fsvfind != fsv.end())
        {
                std::cout<<*fsvfind<<std::endl;

        }

        bool isa = isalpha(10);

        bool isa1 = isalpha('~');

        bool isa2 = isalpha('a');
        int testint = 10;
        TestFun(testint) += 1;

        //test2+=1;


        std::bitset<32> bs;

        bs.set();

        std::cout << bs << std::endl;

        bs.reset(5);

        bs.reset(1);

        std::cout << bs << std::endl;
        return 0;


        LHS::String lhs("this is husheng");

        LHS::String lhs2;
        lhs2 = lhs;
        //std::cout << lhs << std::endl;
        lhs2=lhs2;

        LHS::String lhs3;

        lhs3 = lhs2*lhs;


        std::pair<string,string> pa("abcccc","sf");

        std::cout << pa.first << std::endl;
        std::cout << pa.second << std::endl;

        volatile const int *ap = 0;

        int aa = 100;
        ap = &aa;

        std::complex<string> ca("aaadf", "bdfadfaf");

        std::cout<<ca.imag() <<std::endl;
        std::cout<<ca.real() <<std::endl;

        std::vector<string> vstr(10);
        std::cout <<  vstr.size() << std::endl;


        int maarray[3][4] = {{1,2,3,4},{21,22,23,24},{31,32,33,34}};


        int d[] = {1,2,3,4,5,6};
        myprint(d, d+6);

        int maarray2[3][4] ={1,2,3,4,5};

        int maarray3[3][4]={};

        int maarray4[3][4];


        int arrary3[getSize()];

        for(int i=0; i< 3; i++)
        {
                arrary3[i] = i;
        }

        int array_size = 10;

        int array1[array_size];

        int ia = 0;
        int ib = 0;
        int ic = 0;

        int *array2[3] = {&ia, &ib, &ic};

        for(int i=0; i < 3;i++)
        {
                *array2[i] = i;
        }



        for(int  i =0; i< array_size; i++)
        {
                array1[i] = i;
        }



        int refcn = 1000;
        int rrefcn = refcn;
        rrefcn = 1002;
        int &rrrefcn = refcn;
        rrrefcn = 10023;
        *&rrrefcn = 1024;
        int ccn = 100;
        int *const ccnp = &ccn;
        *ccnp = 120;

        // ccnp++;



        const int cn = 0;

        //cn = 100;

        const int *cnp = &cn;

        cnp++;


        string mystr = "my thisnf";

        std::replace(mystr.begin(), mystr.end(), 'm', 'y');


        const char *c_str = mystr.c_str();

        std::cout << c_str <<std::endl;


        std::cout<< (2<<8) <<std::endl;
        std::map<string, string> amap;

        std::map<string,string>::iterator iter2;

        amap.insert(std::map<string,string>::value_type("1","d"));
        amap.insert(std::map<string,string>::value_type("1","2"));

        std::map<string,string>::iterator afind = amap.find("1");
        while(afind != amap.end())
        {
                std::cout << afind->second << std::endl;
                afind++;
        }
        return 0;

        std::vector<int> vect(10);

        std::vector<int>::iterator iter = vect.begin();
/*
        while(iter != vect.end()){
                *iter = 10;
                iter++;
        }
        int z = vect.at(1);
        std::sort(vect.begin(),vect.end());
        std::find(vect.begin(),vect.end(),10);
        std::reverse(vect.begin(), vect.end());
*/
        vect.push_back(100);
        vect.push_back(12);
        vect.push_back(22);
        vect.push_back(222);
        vect.push_back(21);
        vect.push_back(22);
        vect.push_back(32);
        vect.assign(vect.begin(),vect.end());
        int z1 = vect.capacity();
        int z2 = vect.capacity();

        while(iter!=vect.end())
        {
                std::cout << *iter<< std::endl;
                iter++;
        }

        return 0;

//std::vector vect;

try
{

        int pask = 0;
        int d = 1;
        int z = d/pask;


        //       throw std::string("this is error thrown for testings purpose!");


}catch(std::string errormessage)
{
        std::cerr << errormessage << std::endl;
        return -1;
}catch(...)
{
        std::cerr << "fatal error thrown from programming" << std::endl;
        return -1;
}



        IntArray arr(20);

        TArray<float>  arr_t(10);


        int *a_new = new int(100);

        delete a_new;

        int *array_new = new int[10];

        delete [] array_new;

        int a = 10;
        int *a_point;

        int *b_point = &a;

        *b_point = *b_point  + 100;

        std::cout << a << std::endl;
        std::cout << *b_point << std::endl;



        char *abc = "ddddsfs";

        std::cout << abc << std::endl;
        int array[10] = {1,2,2,3,5,4,3,5,4};
        std::cout << &array << std::endl;
        std::cout << array << std::endl;
        std::cout << array[0] << std::endl;

        std::ofstream file("outfile");
        std::ifstream infile("infile");
        if(!file)
        {
                std::cerr << "failed to open file" << std::endl;
                return -1;
        }

        if(!infile)
        {
                std::cerr << "failed to open infile" <<std::endl;
                return -1;
        }

        std::string input;

        while(infile >> input)
        {
                file << input;
        }

        return 0;
/*
        while(std::cin >> input)
        {
                std::cout << "input is " << input << std::endl;
        }
*/


        std::cout << "this is new line testing" << std::endl;

        std::cerr << "this is error output testing" << std::endl;

//        assert(0!=0);


        #ifdef __cplusplus

        std::cout << "c++ programming \n";
        #else
        std::cout << "c programming \n";
        #endif

//        std::cout << "hello world \n";
        //      std::cout << "abc";
        std::string cur_str = "this is husheng";
        std::vector<std::string> my_vector(20);

        std::cout << cur_str;

        return 0;
}



std::vector<string>* loadfileText()
{
        using namespace std;

        string filename;
        cout<<"please enter filename"<<endl;

        cin >> filename;


        ifstream file(filename.c_str(),ios::in);

        if(!file)

        {
                cerr << "failed to open file" << endl;
        }
        else
        {
                cout << "\n";
        }

        vector<string> *vpointer = new vector<string>;

        typedef pair<string::size_type,int> maxstate;

        maxstate maxline;

        string textline;
        int linenum = 1;
        while(getline(file, textline, '\n'))
        {
                cout<< "read" << textline << endl;

                if(maxline.first < textline.size())
                {
                        maxline.first = textline.size();
                        maxline.second = linenum;
                }

                vpointer->push_back(textline);

                linenum++;

        }


        return vpointer;

}



text_loc* separate_words(vector<string> *textlines)
{
        vector<string> *words = new vector<string>;
        vector<location> *locations = new vector<location>;

        short line_pos = 0;
        for(; line_pos < textlines->size(); line_pos++)
        {
                short word_pos =0;
                string textline = (*textlines)[word_pos];

                string::size_type pos = 0;
                string::size_type prev_pos = 0;

                while((pos = textline.find_first_of(' ',pos))!= string::npos)
                {
                        words->push_back(textline.substr(prev_pos, pos-prev_pos));
                        locations->push_back(make_pair(line_pos,word_pos));
                        word_pos++;
                        pos++;
                        prev_pos = pos;
                }

                words->push_back(textline.substr(prev_pos, pos-prev_pos));
                locations->push_back(make_pair(line_pos,word_pos));



        }

        return new text_loc(words, locations);

}
