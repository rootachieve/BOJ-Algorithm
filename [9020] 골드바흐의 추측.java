import java.io.BufferedWriter;
import java.io.IOException;

import java.io.OutputStreamWriter;
import java.util.Scanner;



public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scin = new Scanner(System.in);
        int arr[] = new int[20020];
        int N = scin.nextInt();
        for(int i=2;i<=20000;i++){
            if(arr[i]==0){
                for(int j=i+i;j<=20000;j+=i){
                    arr[j]=1;
                }
            }
        }

        for(int i=1;i<=N;i++) {
            int C = scin.nextInt();
            int a =C/2;
            int b= a;
            do {
                if(a==b){
                    for(int j=a;j>=2;j--){
                        if(arr[j]==0){
                            a=j;
                            break;
                        }
                    }
                    for(int j=b;j<=20000;j++){
                        if(arr[j]==0){
                            b=j;
                            break;
                        }
                    }
                }else if(a+b>C){
                    for(int j=a-1;j>=2;j--){
                        if(arr[j]==0){
                            a=j;
                            break;
                        }
                    }
                }else if(a+b<C){

                    for(int j=b+1;j<=20000;j++){
                        if(arr[j]==0){
                            b=j;
                            break;
                        }
                    }
                }
                if(a + b == C &&(arr[a]==0&&arr[b]==0)){
                    break;
                }
            } while (a + b != C ||(arr[a]!=0||arr[b]!=0));

            System.out.println(a+" "+b);
        }

    }

}