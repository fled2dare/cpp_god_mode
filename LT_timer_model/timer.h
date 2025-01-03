#pragma once
#include <systemc>

class Timer: public sc_core::sc_module{
    public:
        SC_HAS_PROCESS(Timer);
        Timer(sc_core::sc_module_name name);

        sc_core::sc_in<bool> read_en, write_en, reset;
        sc_core::sc_out<bool> intr0, intr1;

        sc_core::sc_in<uint8_t> addr, data_in;
        sc_core::sc_out<uint8_t> data_out;

    private:
        // all the process inside the timer module
        void timer_logic(void);
        void calculate_interrupts(void);
        void handle_register_process(void);

        sc_core::sc_time clock_interval;


        uint8_t timer_cntrl, timer_val, timer_cmp, timer_intr_status;
};  