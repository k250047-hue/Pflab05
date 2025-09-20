#include<stdio.h>

int main(){
	
	int device_type,code;
	printf("Tech Support Diagonose System");
	printf("enter device type \n1 for laptop\n2 for smartphone\n3 for router\n");
	scanf("%d",&device_type);
	printf("enter symptom code");
    scanf("%d",code);
	switch(device_type){
		case1:
			printf("enter symptom code");
		    scanf("%d",code);
		
		switch(code){
		
			case 10: printf("\n**critical issue**  Wont turn on");
			         printf("Additional advice:Check power adapter and battery connections.");
			         break;
		    case 11: printf("\n**critical issue** Overheating");
		             printf("Clean fans and ensure proper ventilation.");
		             break;
		    case12:  printf("\n**critical issue** Slow Performance");
		             printf("Run system diagnostics and check resource usage.");
		             break;
		}
		break;
			
			
	    case 2:  
	    
	          switch (code){
	          	 	case 20: printf("\n**critical issue**  Battery drain fast");
			         printf("Additional advice:Run battery calibration tool and check for background apps.");
			         break;
		             case 21: printf("\n**critical issue** Battery drains fast");
		             printf("Check SIM card and network settings.");
		             break;
		             case22:  printf("\n**critical issue**  Touchscreen unresponsive");
		             printf("Perform screen calibration test. Clean screen surface.");
		             break;
	         	
	          	
			  }
	       break;
			
		case 3:	
		     
		      switch (code){
	          	 	case 30: printf("\n**critical issue**  No internet connection");
			         printf("Additional advice:Check ISP status and router cables.");
			         break;
		             case 31: printf("\n**critical issue** Wi-Fi signal weak");
		             printf("Reposition router and check antenna connections.");
		             break;
		             case32:  printf("\n**critical issue**  Device cant connect");
		             printf("Check MAC filtering and DHCP settings.");
		             break;	
		
	}
		break;
			
			
			
			
			
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
   return 0;
}

