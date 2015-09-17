#include "sniffer.h"

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{

        static int count = 1;
        const struct sniff_ethernet *ethernet; // ethernet header
        const struct sniff_ip *ip; // ip header
        const struct sniff_tcp *tcp; // tcp header
        const char *payload; // packet payload

        int size_ip;
int size_tcp;
int size_payload;

printf("\nPacket number %d\n", count);
count++;

// ethernet  headers
ethernet = (struct sniff_ethernet*)(packet);

// ip header
ip = (struct sniff_ip*)(packet + ETHERNET_SIZE);
size_ip = IP_HL(ip)*4;
                   if(size_ip < 20)
                   {
                   printf("invaild IP header length: %u by bytes\n",size_ip);
                   }

printf("from: %s\n", inet_ntoa(ip->ip_src));
printf("to: %s\n", inet_ntoa(ip->ip_dst));

// print protocal
switch(ip->ip_p)
{
case IPPROTO_TCP:
        printf("TCP\n");
break;
case IPPROTO_UDP:
        printf("UDP\n");
        break;

case IPPROTO_ICMP:
        printf("UDP\n");
        break;

case IPPROTO_IP:
        printf("UDP\n");
        break;
default:
        printf("protocal: unknown\n");
        return;
}


tcp = (struct sniff_tcp*)(packet+ ETHERNET_SIZE +size_ip);
size_tcp = TH_OFF(tcp)*4;
if(size_tcp <20)
{
        printf("invalid TCP header length: %u bytes\n", size_tcp);
        return;
}

printf("Src port: %d\n", ntohs(tcp->th_sport));

printf("Dst port: %d\n", ntohs(tcp->th_dport));

payload = (u_char*) (packet+ ETHERNET_SIZE +size_ip +size_tcp);

size_payload = ntohs(ip->ip_len) - (size_ip + size_tcp);

if(size_payload >0)
{
        printf("Payload (%d bytes):\n", size_payload);
        print_payload(payload, size_payload);
}

};


void print_payload(const u_char *payload, int len)
{

        int len_rem = len;
        int line_width = 16;
        int line_len;
        int offset = 0;
        const u_char *ch = payload;

        if(len <=0)
        {
                return;
        }
        if(len <= line_width)
        {
                print_hex_ascii_line(ch, len, offset);
                return;
        }


        for(;;)
        {
                line_len = line_width % len_rem;
                print_hex_ascii_line(ch, line_len, offset);

                len_rem =len_rem -line_len;

                ch = ch +line_len;
                offset = offset + line_width;

                if(len_rem <= line_width)
                {
                        print_hex_ascii_line(ch, len_rem, offset);
                        break;
                }
        }
        return;

};

void print_hex_ascii_line(const u_char *payload, int len, int offset)
{
        int i;
        int gap;
        const u_char *ch;

// offset
        printf("%05d   ", offset);

        // hex
        ch = payload;

        for(i=0;i<len;i++)
        {
                printf("%02x ",*ch);
                ch++;

                // print extra space after 8th byte for visual aid
                if(i==7)
                        printf(" ");
        }

        // print space to handle line less than 8 bytes
        if(len < 8)
                printf(" ");


        if(len < 16)
        {
                gap = 16 - len;
                for(i =0; i < gap; i++)
                {
                        printf("   ");
                }
        }

        printf("   ");

        ch = payload;
        for(i = 0; i< len; i++)
        {
                if(isprint(*ch))
                {
                        printf("%c", *ch);

                }
                else
                {
                        printf(".");
                }
                ch++;
        }

        printf("\n");
        return;
}


int main(int args, char* arg[])
{

        char *dev;
        char errbuf[PCAP_ERRBUF_SIZE];

        pcap_t *handle;

        char filter_exp[] ="ip";
        struct bpf_program fp;
        bpf_u_int32 mask;
        bpf_u_int32 net;

        int num_packets = 10;


        if(args == 2)
        {
                dev = arg[1];
        }
        else if (args > 2)
        {

                fprintf(stderr, "error: unre");
                exit(EXIT_FAILURE);
        }
        else
        {
                dev = pcap_lookupdev(errbuf);

                if(dev == NULL)
                {
                        fprintf(stderr,"couldn't find default device: %s\n",errbuf);

                        exit(EXIT_FAILURE);
                }

        }


        if(pcap_lookupnet(dev, &net, &mask, errbuf)== -1)
        {
                fprintf(stderr,"couldn't get netmask for device %s\n", errbuf);
                net =0;
                mask =0;
        }


        printf("Device: %s\n", dev);
        printf("Number of packet: %d\n",num_packets);
        printf("Filter expression: %s\n", filter_exp);


        handle = pcap_open_live(dev,SNF_LEN, 1, 1000, errbuf);

        if(handle == NULL)
        {
                fprintf(stderr,"Couldn't opne device %s, error: %s",dev,errbuf);
                exit(EXIT_FAILURE);
        }

        if(pcap_datalink(handle) != DLT_EN10MB)
        {
                fprintf(stderr, "%s is not an Ethernet\n",dev);
                exit(EXIT_FAILURE);
        }


        if(pcap_compile(handle, &fp, filter_exp, 0, net)==-1)
        {
                fprintf(stderr,"Could't pars filter %s, error: %s\n",filter_exp,pcap_geterr(handle));
                exit(EXIT_FAILURE);
        }

        if(pcap_setfilter(handle
                          , &fp))
        {
                fprintf(stderr,"Couldn't install filter rules %s %s\n", filter_exp,pcap_geterr(handle));
                exit(EXIT_FAILURE);
        }


        pcap_loop(handle, num_packets, got_packet, NULL);


        pcap_freecode(&fp);
        pcap_close(handle);


        printf("\nCapture complete.\n");


        return 0;
}
