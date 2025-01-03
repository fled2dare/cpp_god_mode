#include <systemc>
#include "timer.h"

Timer::Timer(sc_core::sc_module_name name, sc_core::sc_time clock_interval) : sc_core::sc_module(name),clock_interval(clock_interval), timer_cntrl(0), timer_val(0), timer_cmp(0), timer_intr_status(0){
    SC_THREAD(timer_logic);

    SC_THREAD(handle_register_process);
}

Timer::timer_logic(){
    while (true)
    {
        if(reset.read()){
            timer_cntrl = 0;
            timer_val = 0;
            timer_cmp = 0;
            timer_intr_status = 0;

            intr0.write(false);
            intr1.write(false);
        } else if(timer_cntrl & 0x01){
            // this is when timer will work and interrupts will be called as well
            calculate_interrupts();
        }
        wait(clock_interval); // this is for the next reset of timer_enable
    }
}

Timer::calculate_interrupts(){
    /*
    this function calculates the interrupts or say next interrupt based on the clock provided to it!
    */

}

Timer::handle_register_process(){
    while (true)
    {
        if(read_en){
            switch (addr.read())
            {
            case 0x00:
                data_out.write(timer_cntrl);
                break;
            case 0x04:
                data_out.write(timer_val);
                break;
            case 0x08:
                data_out.write(timer_cmp);
                break;
            case 0x0C:
                data_out.write(timer_intr_status);
                break;
            default:
                data_out.write(0x00);
                break;
            }
        }else if(write_en){
            switch (addr.read())
            {
            case 0x00:
                timer_cntrl = data_in.read();
                break;
            case 0x04:
                timer_val = data_in.read();
                break;
            case 0x08:
                timer_cmp = data_in.read();
                break;
            case 0x0C:
                timer_intr_status &= ~data_in.read(); // basically clear the bits in the timer_intr_status which are active in data_in
            default:
                break;
            }
        }
    }
    
}