#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
struct Bus
{
    char busName[25];
    char busFrom[25];
    char busTo[25];
    char busStart[10];
    char busEnd[10];
    int fare;
    int seatsAvailable;


};
struct Bus bus[]=
{
    {"rapid kuantan","kualapahang","kuantan","10:00","13:00",4,30},
    {"rapid pekan","pekan","kualalampur","14:00","18:00",19,40},
    {"xyz","a","b","18:00","23:00",21,28}
};

void showBus()
{
    for(int i=0;i<sizeof(bus)/sizeof(bus[0]);i++)
    {
        printf("\n");
        printf("**------------------------**\n");
        printf("BUS NAME:%s\n",bus[i].busName);
        printf("BUS START FROM:%s\n",bus[i].busFrom);
        printf("TO:%s\n",bus[i].busTo);
        printf("START TIME:%s\n",bus[i].busStart);
        printf("JOURNEY ENDS:%s\n",bus[i].busEnd);
        printf("TICKET FARE:%d\n",bus[i].fare);
        printf("SEATS AVAILABLE:%d\n",bus[i].seatsAvailable);
        printf("\n");
    }
}
void searchBus(char name[])
{
    int flag=0;
    for(int i=0;i<sizeof(bus)/sizeof(bus[0]);i++)
    {
        if(strcmp(name,bus[i].busName)==0)
        {
            flag=1;
        printf("\n");
        printf("Match Found!!....\n");
        printf("**------------------------**\n");
        printf("BUS NAME:%s\n",bus[i].busName);
        printf("BUS START FROM:%s\n",bus[i].busFrom);
        printf("TO:%s\n",bus[i].busTo);
        printf("START TIME:%s\n",bus[i].busStart);
        printf("JOURNEY ENDS:%s\n",bus[i].busEnd);
        printf("TICKET FARE:%d\n",bus[i].fare);
        printf("SEATS AVAILABLE:%d\n",bus[i].seatsAvailable);
        printf("\n");

        }
    }
    if(flag!=1)
    {
        printf("\n");
        printf("No Match Found!!!!\n");

    }

}

int main()
{
    printf("-------WELCOME TO RAPID BUS SERVICES-------\n");
    while(true)
    {
        printf("\n");
        printf("Select any option\n-------------------\n1.See All Bus Information\n2.Search Bus Information\n3.Book Your Journey\n");
        int choice;
        scanf("%d",&choice);
        if(choice==1)
            {
                printf("\n");
                printf("SHOW ALL INFORMMATION\n~~~~~~~~~~~~~~~~~~~~~~~\n");
                showBus();
            }else if(choice==2)
            {
                printf("SEARCH BUS BY NAME\n");
                char name[25];
                fflush(stdin);
                fgets(name,sizeof(name),stdin);
                name[strcspn(name, "\n")] = '\0';
                searchBus(name);

            }
            else if(choice==3)
            {
                printf("--Book Your Journey--\n");
                printf("Enter You Destination~~\n");
                char destination[25];
                fflush(stdin);
                fgets(destination,sizeof(destination),stdin);
                destination[strcspn(destination, "\n")] = '\0';

                printf("Enter Where You Want To Go~~\n");
                char to[25];
                 fflush(stdin);
                fgets(to,sizeof(to),stdin);
                to[strcspn(to, "\n")] = '\0';
                int flag=0;
                for (int i = 0; i < sizeof(bus) / sizeof(bus[0]); i++)
                    {

                        if (strcmp(bus[i].busFrom, destination) == 0 && strcmp(bus[i].busTo, to) == 0)
                        {
                            printf("Bus Available.....\n");
                            printf("\n");
                            printf("BUS STARTS-->%s\n",bus[i].busStart);
                            flag=1;
                            int seatFlag=0;
                            if(bus[i].seatsAvailable>0)
                            {
                                seatFlag=1;
                                printf("Seat Available:%d\n",bus[i].seatsAvailable);
                                printf("How many seats do you want to purchase\n");
                                int decision;
                                scanf("%d",&decision);

                                if(decision<bus[i].seatsAvailable)
                                {
                                    bus[i].seatsAvailable=bus[i].seatsAvailable-decision;
                                    printf("Per Seat Fare:%d\n",bus[i].fare);
                                    printf("Total Price:%d\n",bus[i].fare*decision);
                                        printf("Wait For Confirmation...\n");
                                        printf("Payment Option~\n1.Card\n2.Online Transfer\n");
                                        int choice2;
                                        scanf("%d",&choice2);
                                        if(choice2==1)
                                        {
                                            printf("Scan Your Card---\n\n");
                                            printf("Connecting...\nSeat Confirmed..\n\n");
                                            printf("Your Ticket is printing wait on a moment\nCollect The Ticket!!");
                                        }
                                        else if(choice2==2)
                                        {
                                            printf("Scan QR---\n\n");
                                            printf("Connecting...\nSeat Confirmed..\n\n");
                                            printf("Your Ticket is printing wait on a moment\nCollect The Ticket!!");
                                        }
                                        else
                                        {
                                            printf("validation error!!\n");
                                        }
                                }
                                else
                                {
                                    printf("\n");
                                    printf("Not enough seats\n");
                                }
                            }
                            if(seatFlag!=1)
                            {
                                printf("\n");
                                printf("Seats Not Available\n");
                            }

                        }
                }
                if(flag!=1)
                {
                    printf("No Bus Available\n");
                }

                }

            else
            {
                printf("input validation error!!");
            }

    }
    return 0;
}
