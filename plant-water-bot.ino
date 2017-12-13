Timer pumpTimer(1000, stopPump);
bool pumping = FALSE;

void setup() {
    pinMode(0, OUTPUT);
    pinMode(7, OUTPUT);
    Particle.function("pump", pump);
    Particle.function("stop", stop);
    Particle.variable("pumping", pumping);
}

void loop() {
    
    if(!pumpTimer.isActive() && pumping == TRUE){
        stopPump();
        pumping = FALSE;
    }
    
}

int pump(String args){
    int duration = 0;
    duration = args.toInt()*1000;
    if(duration > 100000){
        duration = 100000;
    }
    digitalWrite(0, HIGH);
    digitalWrite(7, HIGH);
    pumpTimer.changePeriod(duration);
    pumpTimer.start();
    pumping = TRUE;
}

int stop(String args){
    stopPump();
    pumping = FALSE;
}

void stopPump(){
    digitalWrite(0, LOW);
    digitalWrite(7, LOW);
    pumping = FALSE;
}
