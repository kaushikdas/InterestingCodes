package lab.java.gradle.kaushik;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;

public class SensorEvent {
    String id;
    String capability;
    String value;

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getCapability() {
        return capability;
    }

    public void setCapability(String capability) {
        this.capability = capability;
    }

    public String getValue() {
        return value;
    }

    public void setValue(String value) {
        this.value = value;
    }

    @Override
    public String toString() {
        return "SensorEvent{" +
                "id='" + id + '\'' +
                ", capability='" + capability + '\'' +
                ", value='" + value + '\'' +
                '}';
    }

    public static void main(String[] args) {
        SensorEvent sensorEvent = new SensorEvent();
        sensorEvent.setId("100-101-102-103");
        sensorEvent.setCapability("motionSensor");
        sensorEvent.setValue("active");

        System.out.println(sensorEvent.toString());

        Gson json = new GsonBuilder().create();
        String jsonEventString = json.toJson(sensorEvent);
        System.out.println(jsonEventString);
    }
}

/*
 * Execution result
 * SensorEvent{id='100-101-102-103', capability='motionSensor', value='active'}
 * {"id":"100-101-102-103","capability":"motionSensor","value":"active"}
 *
 * 1st one is normal string returned from our toString()
 * 2nd one is the converted JSON string
 */