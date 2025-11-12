#include<stdio.h>

int main(){
	
	int device_type,code;
	printf("Tech Support Diagonose System");
	printf("enter device type \n1 for laptop\n2 for smartphone\n3 for router\n");
	scanf("%d",&device_type);
	printf("enter symptom code: ");
    scanf("%d",&code);
	switch(device_type){
		case 1:
			
		
		switch(code){
		
			case 10: printf("**critical issue**  Wont turn on\n");
			         printf("Additional advice:Check power adapter and battery connections.");
			         break;
		    case 11: printf("**critical issue** Overheating\n");
		             printf("Clean fans and ensure proper ventilation.");
		             break;
		    case 12:  printf("**critical issue** Slow Performance\n");
		             printf("Run system diagnostics and check resource usage.");
		             break;
		}
		break;
			
			
	    case 2:  
	    
	          switch (code){
	          	 	case 20: printf("**critical issue**  Battery drain fast\n");
			         printf("Additional advice:Run battery calibration tool and check for background apps.");
			         break;
		             case 21: printf("**critical issue** No signal\n");
		             printf("Check SIM card and network settings.");
		             break;
		             case 22:  printf("**critical issue**  Touchscreen unresponsive\n");
		             printf("Perform screen calibration test. Clean screen surface.");
		             break;
	         	
	          	
			  }
	       break;
			
		case 3:	
		     
		      switch (code){
	          	 	case 30: printf("**critical issue**  No internet connection\n");
			         printf("Additional advice:Check ISP status and router cables.");
			         break;
		             case 31: printf("**critical issue** Wi-Fi signal weak\n");
		             printf("Reposition router and check antenna connections.");
		             break;
		             case 32:  printf("**critical issue**  Device cant connect\n");
		             printf("Check MAC filtering and DHCP settings.");
		             break;	
		
	}
		break;	
			
	}
     return 0;
}
   
