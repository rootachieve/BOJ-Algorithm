import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scin = new Scanner(System.in);
        int N = scin.nextInt();

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int arr[][] =  new int[2200][2200];

        for (int Y = 0; Y < N; Y++) {
            for (int X = 0; X < N; X++) {
                for(int w=1;w*3<=N;w*=3){
                    if((X/w%3==1&&Y/w%3==1)){
                        arr[Y][X]=1;
                    }
                }
            }
        }
        String a = " ";
        String b = "*";
        for (int Y = 0; Y < N; Y++) {
            for (int X = 0; X < N; X++) {
                if(arr[Y][X]==1){
                    bw.write(a);
                }else{
                    bw.write(b);
                }
            }
            bw.newLine();
        }
        bw.flush();
    }
}