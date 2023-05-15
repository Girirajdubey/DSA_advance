#include<stdio.h>
int static count = 0;
struct data{
    float profit;
    int weight;
    float ppw;
};
int bag_size =20 ;
float gross_proft=0;


struct data list[]={{25,18,0},{15,10,0},{24,15,0}};


void sort_struct_array(struct data list[] , int num ){
    int k,z;
    for(k= 0 ; k< num ; k++){
        for(z=k+1; z<num ; z++){
            if(list[k].ppw<list[z].ppw){
                struct data temp = list[k];
                list[k]=list[z];
                list[z]=temp;
            }
            

        }
        
    }
    for(int i= 0 ; i< num; i++){
        printf("\n list[%d] -- profit > %f",i,list[i].ppw);
        printf("\n-------------------------\n");

    }
    printf("\n end of sorting ");
}


  
void ppw(struct data list[],int num){
    for(int i=0 ; i<num;i++){ // profit / weight 
        float temp=(list[i].profit)/(list[i].weight);
        list[i].ppw=temp;
    }
}
void knappy(struct data list[],int num ){
    // get proft per weight and 
    ppw(list,num);
    sort_struct_array(list,num); //sorted as non increasing order 
    int i=0;
    while(bag_size>0 && bag_size>=list[i].weight){
        bag_size= bag_size-list[i].weight;
        gross_proft=gross_proft+list[i].profit;
        i++;
    }
    if(bag_size>0){
        float fraction_weight=(float)(bag_size)/(list[i].weight); // **** type casting is must other wise question wise  u will get wrong answer 
        float  aux=fraction_weight*(list[i].profit);
        gross_proft= gross_proft + aux;
    }
    return;

}


int main(){
    struct data list[]={{25,18,0},{15,10,0},{24,15,0}};
    int num = 3;
    ppw(list,num);
    knappy(list,num);
   
    printf("\n\n\n the gross profit %f",gross_proft); // 3 is size ;

    return 0;

}
