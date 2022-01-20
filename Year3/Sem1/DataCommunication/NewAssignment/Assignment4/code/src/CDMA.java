import java.util.Arrays;

public class CDMA {
    int[][] wtable;
    int[][] copy;
    int[] channel_seq;

    public String setUp(int[] data, int num_stations) {
        StringBuilder dataStr = new StringBuilder();
        wtable = new int[num_stations][num_stations];
        copy = new int[num_stations][num_stations];

        //creating walsh table
        buildWalshTable(num_stations, 0, num_stations - 1, 0,
                num_stations - 1, false);

        showWalshTable(num_stations);

        //create copy of walsh table
        for (int i = 0; i < num_stations; i++) {

            for (int j = 0; j < num_stations; j++) {
                copy[i][j] = wtable[i][j];
                wtable[i][j] *= data[i];
            }
        }

        channel_seq = new int[num_stations];

        for (int i = 0; i < num_stations; i++) {

            for (int j = 0; j < num_stations; j++) {
                // Adding all sequences to get channel sequence
                channel_seq[i] += wtable[j][i];
            }
        }
        System.out.println("Data is " + Arrays.toString(channel_seq));
        for (int i : channel_seq) {
            dataStr.append(i);
        }
        return dataStr.toString();

    }

    public void buildWalshTable(int len, int i1, int i2, int j1,
                                int j2, boolean isBar) {

        if (len == 2) {

            if (!isBar) {

                wtable[i1][j1] = 1;
                wtable[i1][j2] = 1;
                wtable[i2][j1] = 1;
                wtable[i2][j2] = -1;
            } else {

                wtable[i1][j1] = -1;
                wtable[i1][j2] = -1;
                wtable[i2][j1] = -1;
                wtable[i2][j2] = +1;
            }

            return;
        }

        int midi = (i1 + i2) / 2;
        int midj = (j1 + j2) / 2;

        buildWalshTable(len / 2, i1, midi, j1, midj, isBar);
        buildWalshTable(len / 2, i1, midi, midj + 1, j2, isBar);
        buildWalshTable(len / 2, midi + 1, i2, j1, midj, isBar);
        buildWalshTable(len / 2, midi + 1, i2, midj + 1, j2, !isBar);

    }

    public void showWalshTable(int num_stations) {

        System.out.print("\n");

        for (int i = 0; i < num_stations; i++) {
            for (int j = 0; j < num_stations; j++) {
                System.out.print(wtable[i][j] + " ");
            }
            System.out.print("\n");
        }
        System.out.println("-------------------------");
        System.out.print("\n");
    }

    public void receiver(int noOfStations, String dataStr, String[] allRecieverData) {


        for(int x=0;x<noOfStations;x++){
            int product = 0;
            int cnt = 0;

            if(allRecieverData[x] == null){
                allRecieverData[x] = "";
            }

            for (int j = 0; j < dataStr.length(); ++j) {
                if (dataStr.charAt(j) != '-') {
                    cnt++;
                }
            }
         //   System.out.println("count is " + cnt);
            System.out.println("Data is " + dataStr);
            int[] channel_seq = new int[cnt];
            int j = 0;
            int i = 0;

            //converting string data to int
            while (j < cnt) {
                if (dataStr.charAt(i) == '-') {
                    String str = dataStr.substring(i, i + 2);
                  //  System.out.println("TO convert string is" + str);
                    i += 2;
                    channel_seq[j] = Integer.parseInt(str);
                } else {
                    System.out.println(dataStr.charAt(i));
                    channel_seq[j] = Integer.parseInt(dataStr.charAt(i) + "");
                    i++;
                }
                j++;
            }

            System.out.println(Arrays.toString(channel_seq));
            System.out.println();

            //
            for (int k = 0; k < noOfStations; ++k) {
                product += wtable[x][k] * channel_seq[k];
            }
            int data = product / noOfStations;
            System.out.println("Dat is "+data);
            if (data == 1) {
                allRecieverData[x] = allRecieverData[x] + data;
                System.out.println("The data received is from station" + (x + 1) + " is " + data);
            } else if (data == -1) {
                allRecieverData[x] += 0;
                System.out.println("The data received is from station" + (x + 1) + " is " + (0));
            } else {
                System.out.println("Channel didn't sent any data.");
            }
        }

    }

    public void setUp(int num_stations) {
        wtable = new int[num_stations][num_stations];
        copy = new int[num_stations][num_stations];
        buildWalshTable(num_stations, 0, num_stations - 1, 0,
                num_stations - 1, false);

    }
}
