package Models;

import java.io.Serializable;
import java.util.HashMap;

public class Data implements Serializable {
    String type;
    HashMap<String, String> data;

    public Data() {
        data = new HashMap<>();
        this.type = "guest";
    }

    public String get(String key) {
        return data.getOrDefault(key, "no data");
    }

    public void setType(String type) {
        this.type = type;
    }

    public HashMap<String, String> getData() {
        return data;
    }

    public String getRole() {
        return this.type;
    }
}
