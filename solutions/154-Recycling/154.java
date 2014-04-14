import java.io.*;
import java.util.*;

class Main
{
    public static class Bin
    {
        public int[] bin;

        public Bin(String line)
        {
            bin = new int[5];

            set(line, 0, 2);
            set(line, 4, 6);
            set(line, 8, 10);
            set(line, 12, 14);
            set(line, 16, 18);
        }
    
        public int difference(Bin other)
        {
            int diff = 0;
            for(int i = 0; i < 5; ++i)
                if(this.bin[i] != other.bin[i]) ++diff;
            return diff;
        }

        private void set(String line, int a, int b)
        {
            // DEBUG System.out.println("SET [" + line.charAt(a) + "] = [" + line.charAt(b) + "]");

            switch(line.charAt(a))
            {
            case 'r':
                bin[0] = line.charAt(b);
                break;
            case 'o':
                bin[1] = line.charAt(b);
                break;
            case 'y':
                bin[2] = line.charAt(b);
                break;
            case 'g':
                bin[3] = line.charAt(b);
                break;
            case 'b':
                bin[4] = line.charAt(b);
                break;
            }
        }
    }

    public static void main (String args[]) throws java.io.IOException
    {
        final BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        Bin all[] = new Bin[256];
        int index = 0;

        while(true)
        {
            String line = reader.readLine();

            // DEBUG System.out.println("LINE = [" + line + "]");

            if(line.charAt(0) == '#')
                break;

            if(line.charAt(0) == 'e')
            {
                int min_value = 1024;
                int min_index = 0;

                int cache[][] = new int[index][index];

                for(int i = 0; i < index; ++i)
                    for(int j = 0; j < index; ++j)
                        cache[i][j] = -1;

                // DEBUG System.out.println("INDEX [" + index + "]");

                for(int i = 0; i < index; ++i)
                {
                    int d = 0;

                    for(int j = 0; j < index; ++j)
                    {
                        if(i == j) continue;
                        if(cache[i][j] == -1)
                        {
                            // DEBUG System.out.println("Compare [" + i + "] [" + j + "] d = " + d);
                            cache[i][j] = cache[j][i] = all[i].difference(all[j]);
                        }
                        d += cache[i][j];
                        if (d >= min_value) break;
                    }

                    if(d < min_value)
                    {
                        min_value = d;
                        min_index = i;
                        // DEBUG System.out.println("SET min = " + min_value + " index = " + min_index);
                    }
                }

                System.out.println(min_index + 1);

                index = 0;
                continue;
            }

            all[index++] = new Bin(line);
        }
    }
}
