
unsigned long current_time;

// Values for irragation cicle
long irrigation_time = 15L*1000L;
long dry_time = 6L*60L*1000L;
unsigned long current_irrigation_cycle = millis(); 
boolean is_irrigation = true; // Irrigation ON with start arduino

int irrigation_pin = 3;

void setup() {
  pinMode(irrigation_pin, OUTPUT); 
}

  
void loop() {
  current_time = millis();
  
// Check irrigation
 if (is_irrigation){
   check_process(irrigation_time, current_irrigation_cycle, 
   irrigation_pin, is_irrigation, false, HIGH);
 }
  else{
    check_process(dry_time, current_irrigation_cycle, 
    irrigation_pin, is_irrigation, true, LOW);
  } 
}

// Method for compare any cycle working current time and this cycle total time, 
// if this time is greater than total time - set cycle to stop, set LOW/HIGH 
// on its pin and set current time to current cycle time.
void check_process(long proc_time, unsigned long &current_proc_cycle, 
int pin, boolean &is_key, boolean key_value, int high_low){
  if(current_time - current_proc_cycle > proc_time){
      is_key = key_value;
      digitalWrite(pin, high_low);
      current_proc_cycle = current_time;
   } 
}
