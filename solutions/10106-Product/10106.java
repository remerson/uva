import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws Exception {

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        while(true)
        {
            String line = reader.readLine();
            
            //System.out.println("Read line: " + line);

            if(line == null)
                break;

            BigInteger a = new BigInteger(line);

            line = reader.readLine();
            
            BigInteger b = new BigInteger(line);

            //System.out.println("index: " + index);

            System.out.println(a.multiply(b).toString());
        }
    }
}
