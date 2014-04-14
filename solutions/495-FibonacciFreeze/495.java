import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws Exception {

        final int F_MAX = 5001;

        BigInteger[] fibs = new BigInteger[F_MAX];

        fibs[0] = new BigInteger("0");
        fibs[1] = new BigInteger("1");

        for(int i = 2; i < F_MAX; ++i)
        {
            fibs[i] = fibs[i-2].add(fibs[i-1]);
        }


        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        while(true)
        {
            String line = reader.readLine();
            
            //System.out.println("Read line: " + line);

            if(line == null)
                break;

            int index = Integer.parseInt(line);

            //System.out.println("index: " + index);

            System.out.println("The Fibonacci number for " + index + " is " + fibs[index].toString());
        }
    }
}
