import java.io.*;
import java.util.*;

class Main
{
    public static void main (String args[]) throws java.io.IOException
    {
        final BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        
        int t = Integer.parseInt(reader.readLine());
        
        // DEBUG System.out.println("T = [" + t + "]");
        
        String[] values = new String[16];

        for(int q = 1; q <= t; ++q)
        {
            int i = 0;

            StringTokenizer tokenizer = new StringTokenizer(reader.readLine());

            while(tokenizer.hasMoreTokens())
                values[i++] = tokenizer.nextToken();

            int mid = Integer.parseInt(values[0]) / 2 + 1;

            // DEBUG System.out.println("MID = [" + mid + "]");

            System.out.println("Case " + q + ": " + values[mid]);
        }
    }
}
