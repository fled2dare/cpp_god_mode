# SystemC Interview Questions

## SystemC and why do we need it?

SystemC is a library, for modelling/describing and simulating hardware from abstract to detailed level, it extends C++.

- It helps in reducing the design complexity, it allows design systems at higher abstraction level, making it easier to manage complexity and focus on system functionality.
- Early validation and prototyping(helps in fixing design flaws before the hardware is physically realized).
- Helps the software/firmware team, they get a hardware on which they can write/test their software, basically HW SW development can happen at the same time.

## Context-Switching 

Context-switching refers to the process of storing the state of a process or thread so that it can be resumed later. This involves saving the state of the currently running process and loading the saved state of another process. In SystemC, this is relevant primarily for SC_THREAD where the simulation kernel needs to save the context each time a `wait()` is encountered and restore it when the thread is scheduled to resume.

## Difference between SC_THREAD and SC_METHOD

**SC_METHOD:** 
- non-preemptive, meaning once it starts, it runs to completion w/o any interruption. Best for modelling combination circuit. `wait()` can't be used.
- it doesn't support context-switching - that's why it has very low overhead. There is no need to save the state(context) of the process, as it does not maintain state between activations.

**SC_THREAD:**
- preemtive, it can be paused and resumed. It is suitable for modelling sequential logic and can contain synchronization points(`wait()` statement), allowing it to wait for events, time.
- it maintains state between activations, it can pause at the `wait()` statements and resume later, which requires saving and restoring its context. This context switching intruduces additional overhead.

## What is SystemC SC_HAS_PROCESS?

The `SC_HAS_PROCESS` macro in SystemC is a critical component used within the definitions of modules that contain processes(such as SC_THREAD, SC_METHOD or SC_CTHREAD).

`SC_HAS_PROCESS` is used to declare that the SystemC module contains one or more processes. It must be included in the constructor of any module class that uses processes. This macro enables the registration of processes with the SystemC kernel, which is necessary for the kernet to manage and schedule these processes during simulation.

Using SC_HAS_PROCESS ensures that the SystemC simulation kernel is aware of all the processes in a module. This registration is vital for the correct operation of simulations, as it affects how processes are initiated, synchronized, and managed during the run-time of the simulation.

## TLM1.0 vs TLM2.0

### TLM1.0

- Basic Transaction-Level Communication: enabled the representation of communication between system components at a level above cycle accurate interconnect modelling; this was done using APIs and interface. 

- Limited Standardization: While it introduced the concepts of transation-level modelling, it lacked detailed standardization, leading to variations in implementation and interoperability issues among different tools and models.

### TLM2.0

- Base Protocol: defines how transactions are managed and communicated between components, leading to better interoperability and easier integration of components from different sources.
- Generic Payload: introduction of standardized generic payload that could be used across different types of transactions, ensuring uniformity and reducing the need for custom transaction objects.
- Phases and Temporal Decoupling: Multiple phases introduced within a transaction whichi allows for more detailed and accurate modelling of transactions. Temporal decoupling allows different parts of the model to run ahead in time independently before synchronizing, significantly improving simulation speeds.
- Blocking and non-blocking interfaces: blocking for detailed control and non-blocking for high performance.
- DMI: introduced to bypass the regular transport interfaces for frequent memory access, thus enhancing simulation performance in certain scenarios.

## About Generic Payload

Designed to be flexible and extensible to handle a variety of transaction types across different modelling domains and scenarios. It includes all the information to perform a transaction between components in a system model.

### Components of the generic payload

This typically includes:
    - data length
    - command
    - data pointer
    - response status
    - address

