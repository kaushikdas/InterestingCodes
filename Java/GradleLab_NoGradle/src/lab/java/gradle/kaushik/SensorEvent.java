package lab.java.gradle.kaushik;

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
    }
}

/*
 * Execution result
 * SensorEvent{id='100-101-102-103', capability='motionSensor', value='active'}
 */
