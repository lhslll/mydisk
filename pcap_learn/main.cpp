#include <iostream>
#include <pcap.h>
#include <string>

using namespace std;
int main()
{
        // string devS("eth0");
        char *dev;// = devS.c_str();
        char errorBuf[PCAP_ERRBUF_SIZE];

        const u_char *packet;
        struct pcap_pkthdr header;


        dev = pcap_lookupdev(errorBuf);
        if(dev == NULL)
        {
                cout << errorBuf<< endl;
        }

        pcap_t *handle;

        handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errorBuf);

        if(handle == NULL)
        {
                cerr << errorBuf << endl;
        }

        int dltType = pcap_datalink(handle);


        packet = pcap_next(handle, &header);

        pcap_close(handle);

        return 0;
}
