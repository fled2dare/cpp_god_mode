#pragma once
#include <systemc>

class Testbench : public sc_core::sc_module {
public:
    sc_core::sc_out<bool> reset_out, read_en_out, write_en_out;
    sc_core::sc_out<uint8_t> addr_out, data_in_out;
    sc_core::sc_in<uint8_t> data_out_in;
    sc_core::sc_in<bool> intr0_in, intr1_in;

    SC_HAS_PROCESS(Testbench);
    Testbench(sc_core::sc_module_name name);

    void set_interrupt_messages(bool enable);

private:
    bool interrupt_messages_enabled;

    void test_logic();
    void monitor_interrupts();

    void write_register(uint8_t address, uint8_t value);
    uint8_t read_register(uint8_t address);
};
