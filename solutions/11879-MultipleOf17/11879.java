import java.io.*;
import java.util.*;
import java.math.*;

class Main
{
    public static void main (String args[]) throws java.io.IOException
    {
        final BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        BigInteger s = BigInteger.valueOf(17);

        while(true)
        {
            String line = reader.readLine();

            // DEBUG System.out.println("LINE = [" + line + "]");

            if(line.charAt(0) == '0')
                break;

            int d;
            if(line.length() > 1)
            {
                d = line.charAt(line.length() - 1);
                d -= 48;
            }
            else
            {
                System.out.println("0");
                continue;
            }

            // DEBUG System.out.println("d = [" + d + "]");

            BigInteger e = BigInteger.valueOf(5 * d);

            BigInteger val = new BigInteger(line.substring(0, line.length() - 1));

            // DEBUG System.out.println("val = [" + val.toString() + "]");

            if(val.subtract(e).mod(s) == BigInteger.ZERO)
                System.out.println("1");
            else
                System.out.println("0");
        }
    }
}

