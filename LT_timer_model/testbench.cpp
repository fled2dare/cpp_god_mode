#include <systemc>
#include "testbench.h"

Testbench::Testbench(sc_core::sc_module_name name): sc_core::sc_module(name), interrupt_messages_enabled(false){
    SC_THREAD(test_logic);

    SC_METHOD(monitor_interrupts);
    sensitive << intr0_in << intr1_in;
}

void Testbench::set_interrupt_messages(bool enable){
    interrupt_messages_enabled = enable;
}

void Testbench::test_logic(){
    write_register(0x00, 0x00);
    write_register(0x08, 0x00);
    write_register(0x0C, 0x00);

    write_register(0x00, 0x06);

    set_interrupt_messages(true);

    wait(sc_core::SC_ZERO_TIME);
    write_register(0x08, 135);

    wait(100, sc_core::SC_NS);
    write_register(0x00, 0x07);

    wait(9135, sc_core::SC_NS);
    uint8_t val = read_register(0x04);
    std::cout << "Timer Value @ " << sc_core::sc_time_stamp() << ": " << int(val) << std::endl;

    wait(760, sc_core::SC_NS);
    val = read_register(0x04);
    std::cout << "Timer Value @ " << sc_core::sc_time_stamp() << ": " << int(val) << std::endl;

    wait(5, sc_core::SC_NS);
    write_register(0x00, 0x06);

    wait(250, sc_core::SC_NS);
    val = read_register(0x04);
    std::cout << "Timer Value @ " << sc_core::sc_time_stamp() << ": " << int(val) << std::endl;

    wait(750, sc_core::SC_NS);
    write_register(0x00, 0x07);

    wait(3995, sc_core::SC_NS);
    val = read_register(0x04);
    std::cout << "Timer Value @ " << sc_core::sc_time_stamp() << ": " << int(val) << std::endl;

    wait(5, sc_core::SC_NS);
    write_register(0x08, 185);

    wait(5000, sc_core::SC_NS);
    set_interrupt_messages(false);

    wait(980000, sc_core::SC_NS);
    set_interrupt_messages(true);

    wait(750, sc_core::SC_NS);
    val = read_register(0x04);
    std::cout << "Timer Value @ " << sc_core::sc_time_stamp() << ": " << int(val) << std::endl;

    wait(4250, sc_core::SC_NS);
    set_interrupt_messages(false);
}

void Testbench::monitor_interrupts(){
    if(interrupt_messages_enabled){
        if(intr0_in){
            std::cout << "INterrupt asserted: Intr0 (" << sc_core::sc_time_stamp() << ")" << std::endl;
        }
        if(intr1_in){
            std::cout << "INterrupt asserted: Intr1 (" << sc_core::sc_time_stamp() << ")" << std::endl;
        }
    }
}

void Testbench::write_register(uint8_t address, uint8_t value){
    addr_out.write(address);
    data_in_out.write(value);
    write_en_out.write(true);
    wait(sc_core::SC_ZERO_TIME);
    write_en_out.write(false);
}

uint8_t Testbench::read_register(uint8_t address){
    addr_out.write(address);
    read_en_out.write(true);
    wait(sc_core::SC_ZERO_TIME);
    read_en_out.write(false);
    return data_out_in.read();
}