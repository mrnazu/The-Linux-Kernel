# The Linux Kernel
vmlinuz-[kernel verion] 
(vmlinuz-2.0.1)

## Intro

The Linux kernel is the core component of the Linux operating system. It serves as the bridge between the hardware and the user-level software, managing system resources, providing essential services, and facilitating communication between software and hardware components.

The kernel is a piece of program that is loaded into memory during the boot process and remains resident in memory throughout the computer's operation.
 
When I say that the Linux kernel is "loaded into memory," I'm referring to the process of loading the kernel from the storage device (typically a hard disk or SSD) into the computer's RAM (Random Access Memory) during the system boot. The RAM is a volatile type of memory that loses its contents when the power is turned off, unlike the non-volatile storage on a hard disk.

1. **BIOS/UEFI:**
   - When you turn on your computer, the Basic Input/Output System (BIOS) or the Unified Extensible Firmware Interface (UEFI) is responsible for initializing hardware components and starting the boot process.

2. **Bootloader:**
   - The bootloader (such as in Linux GRUB or LILO in others) is a small program that is loaded by the BIOS/UEFI. The bootloader's primary function is to locate the operating system kernel on the storage device and load it into memory.

3. **Kernel Loading:**
   - Once the bootloader identifies the location of the Linux kernel on the storage device (e.g., a specific partition on the hard disk), it loads the kernel into the computer's RAM.

4. **Kernel Initialization:**
   - The kernel initializes itself and starts the essential components required for the operating system to function. This includes setting up the initial process, initializing device drivers, and configuring memory management.

5. **User Space:**
   - Once the kernel is loaded and initialized, control is transferred to the user space, where user-level processes and applications can run.

The reason for loading the kernel into memory is that RAM is much faster than accessing data directly from a hard disk. By loading the kernel into memory, the operating system can execute instructions and access data more quickly, improving overall system performance.

After the kernel is loaded into memory, it remains resident there as long as the system is running. The kernel manages the interaction between hardware and software, handling tasks such as process management, device communication, and memory allocation throughout the system's operation.



## The Linux Kernel API

The Linux kernel provides an Application Programming Interface (API) that allows user-space programs to interact with the kernel and utilize its functionalities. The kernel API defines a set of `system calls`, `functions`, `data structures`, and `conventions` that applications can use to request services from the kernel. The linux kernel also provides virtual file systems, `proc`, `sys`, `debugfs` through those we can intract dirctly with the kernel.

Here are some key components of the Linux kernel API:

1. **System Calls:**
   - System calls are the primary interface between user-space applications and the kernel. They provide a way for programs to request privileged operations and access kernel services. Examples of system calls include `open`, `read`, `write`, `fork`, `execve`, and `ioctl`.

2. **C Library (libc):**
   - The C library is an integral part of the Linux API. It provides a higher-level interface for applications, wrapping the low-level system calls. Functions such as `printf`, `malloc`, and `fopen` are part of the C library and serve as a bridge between user-space and the kernel.

3. **File Descriptors:**
   - File descriptors are used to represent open files, sockets, and other I/O resources. System calls like `open` and `socket` return file descriptors, which are then used in subsequent system calls for reading, writing, or manipulating the associated resources.

4. **Process Control:**
   - System calls related to process control allow programs to create, manage, and communicate between processes. Examples include `fork`, `execve`, `exit`, and `waitpid`.

5. **Memory Management:**
   - Memory-related system calls enable programs to allocate and deallocate memory, as well as manipulate memory protections. Functions like `malloc`, `free`, `mmap`, and `munmap` are part of the memory management API.

6. **Synchronization and IPC (Inter-Process Communication):**
   - System calls related to synchronization and IPC enable communication and coordination between processes. Examples include `semaphore` and `message queues`.

7. **Network and Socket API:**
   - The kernel provides a network API for networking-related operations. The socket API allows applications to create, bind, and communicate over network sockets.

8. **Device Drivers:**
   - Device drivers provide an API for interacting with hardware devices. Applications can communicate with devices through the appropriate device file and use system calls like `ioctl` for specific device operations.

9. **Virtual File System (VFS):**
   - The VFS is an abstraction layer that allows different file systems to be accessed using a common API. Applications interact with files using standard file-related system calls.

10. **ioctl:**
    - The `ioctl` system call is a versatile interface used for controlling various device-specific operations and configurations.

## Kernel Architecture of Linux
![image](https://github.com/mrnazu/The-Linux-Kernel/assets/108541991/151b69c0-b4f7-4e57-940b-0aa1f2948cec)

- Applications call functions in lib. some of those functions invoke kernel system calls and the kernel is responsible for intracting with the hardware.

## Commands for Hardware info
Linux provides several commands that allow you to gather information about hardware components and system configuration. Here are some commonly used commands for retrieving hardware information in a Linux environment:

1. **`lscpu`**:
   - Displays information about the CPU (Central Processing Unit), including its architecture, number of cores, and other relevant details.

   ```bash
   lscpu
   ```

2. **`lsblk`**:
   - Lists information about block devices, including hard drives and partitions.

   ```bash
   lsblk
   ```

3. **`lspci`**:
   - Provides information about PCI buses and devices connected to them, including graphics cards, network adapters, and other PCI devices.

   ```bash
   lspci
   ```

4. **`lsusb`**:
   - Lists USB devices and related information.

   ```bash
   lsusb
   ```

5. **`dmidecode`**:
   - Retrieves information from the system DMI (Desktop Management Interface) table, which contains details about the system's hardware components.

   ```bash
   sudo dmidecode
   ```

6. **`cat /proc/cpuinfo`**:
   - Displays detailed information about the CPU, including model, vendor, and supported features.

   ```bash
   cat /proc/cpuinfo
   ```

7. **`cat /proc/meminfo`**:
   - Shows information about system memory, including total and available RAM.

   ```bash
   cat /proc/meminfo
   ```

8. **`df -h`**:
   - Provides information about disk space usage on mounted filesystems.

   ```bash
   df -h
   ```

9. **`free -m`**:
   - Shows information about system memory usage.

   ```bash
   free -m
   ```

10. **`inxi`**:
    - A versatile command-line system information tool that provides detailed information about various hardware components.

    ```bash
    inxi -Fx
    ```

11. **`hwinfo`**:
    - A command that provides detailed hardware information.

    ```bash
    sudo hwinfo
    ```

12. **`lshw`**:
    - Lists detailed information about hardware components on the system.

    ```bash
    sudo lshw
    ```

Keep in mind that some of these commands might require administrative privileges, so you may need to use `sudo` to execute them. Additionally, the availability of these commands can vary based on the Linux distribution and the specific tools installed on your system.

## Commands for Hardware Control and Config
Controlling and configuring hardware in the Linux kernel often involves using configuration files, modules, and specific tools for interacting with hardware devices. Here are some commands and tools you can use for hardware configuration and control in Linux:

1. **`modprobe`**:
   - Loads and unloads kernel modules, which are often used to add or remove support for specific hardware devices or features.

   ```bash
   sudo modprobe <module_name>
   ```

2. **`lsmod`**:
   - Lists currently loaded kernel modules.

   ```bash
   lsmod
   ```

3. **`rmmod`**:
   - Removes (unloads) a kernel module.

   ```bash
   sudo rmmod <module_name>
   ```

4. **`dmesg`**:
   - Displays messages from the kernel ring buffer, providing information about hardware detection and events.

   ```bash
   dmesg
   ```

5. **`udevadm`**:
   - Allows you to control the `udev` daemon, which manages device events and provides a dynamic device management infrastructure.

   ```bash
   udevadm control --reload-rules
   ```

6. **`lshw`**:
   - Lists detailed information about hardware components, and it can be used to view or print detailed configuration for specific hardware.

   ```bash
   sudo lshw
   ```

7. **`lspci`** and **`lsusb`**:
   - These commands were mentioned earlier for displaying information about PCI and USB devices. They can also be used to identify hardware for further configuration.

   ```bash
   lspci
   lsusb
   ```

8. **`ethtool`**:
   - Provides information about and configuration options for Ethernet devices.

   ```bash
   sudo ethtool <interface_name>
   ```

9. **`hdparm`**:
   - A command-line utility to set and view ATA hard disk drive parameters.

   ```bash
   sudo hdparm -I /dev/sdX
   ```

10. **`iwconfig`**:
    - Displays and allows configuration of wireless network interfaces.

    ```bash
    iwconfig
    ```

11. **`sysctl`**:
    - Controls kernel parameters at runtime. It can be used to tweak various aspects of the kernel's behavior, including networking parameters.

    ```bash
    sudo sysctl -w <parameter=value>
    ```

## Let's talk about system call.
System calls are the mechanism by which user-space programs interact with the kernel in an operating system. When a program needs access to certain privileged functionalities, such as interacting with hardware, managing processes, or accessing files, it makes a request to the kernel through a system call. 

![image](https://github.com/mrnazu/The-Linux-Kernel/assets/108541991/c7fbd9ce-ada3-4e8a-b9ee-4974bf53c368)


Here's an overview of the mechanics behind system calls:

1. **User-Space to Kernel-Space Transition:**
   - When a user-space program needs to perform an operation that requires kernel privileges, it triggers a system call. This is typically done through a high-level language-specific interface (e.g., C library functions like `open()`, `read()`, `write()`).

2. **System Call Number:**
   - Each system call has a unique identifier, known as the system call number. This number is used to identify the specific operation the program is requesting. The system call number is often passed in a register or a specific CPU register (e.g., `eax` on x86 architecture).

3. **Arguments:**
   - System calls may require additional parameters or arguments to provide necessary information about the operation. These arguments are often passed in registers or on the program's stack, depending on the architecture.

4. **Kernel Mode Activation:**
   - The processor switches from user mode to kernel mode to execute the system call. This switch involves changing the processor's execution level to allow privileged instructions to be executed.

5. **Interrupt or Exception Handling:**
   - The transition to kernel mode is typically triggered by an interrupt or an exception. Software interrupts (e.g., `int 0x80` on x86) or system call instructions initiate the switch to kernel mode. The processor responds to these events by executing a designated kernel routine.

6. **System Call Table:**
   - The system call number is used to index into a system call table, which is an array of function pointers in the kernel. Each entry in the table corresponds to a specific system call, and the associated function is invoked.

7. **Kernel Execution:**
   - The kernel now executes the requested system call on behalf of the user-space program. It validates the arguments, performs the requested operation, and prepares the results (if any).

8. **Return to User Mode:**
   - After the system call is executed, the kernel returns control to the user mode. This involves restoring the user-mode execution context and switching back to user mode.

9. **Return Value:**
   - The result of the system call is often returned to the user-space program. This could be a status code indicating success or failure, and additional information may be provided through function return values or pointers to user-space buffers.

The exact mechanics can vary based on the architecture and the operating system. For example, x86 and ARM architectures may have different assembly instructions for initiating system calls. Additionally, the kernel interface and system call numbers can differ between operating systems (e.g., Linux, Windows).

Understanding system call mechanics is fundamental to understanding how user-space programs interact with the kernel and leverage its capabilities while maintaining a clear separation between user space and kernel space.

**Real World Example:**
Let's take the example of the `open()` system call, which is used to open files. Here's a simplified overview:

1. In user space, a program calls the `open()` function from the C library.

2. The `open()` function translates this high-level call into a system call number (e.g., using the `syscall()` function).

3. The `syscall()` function triggers the `int 0x80` instruction on x86, signaling a software interrupt and switching the processor to kernel mode.

4. The interrupt handler or assembly code responsible for handling system calls looks up the system call number (e.g., `__NR_open` defined in `unistd.h`), finds the corresponding C function pointer in the system call table, and calls the `sys_open()` C function.

5. The `sys_open()` C function, implemented in the kernel's `fs/open.c` file, performs the necessary operations to open the requested file, checks permissions, and returns the file descriptor to the calling program.

6. Control is then returned to user space, and the file descriptor is available to the program.

This example demonstrates how a user-space program interacts with the kernel using the `open()` system call, illustrating the journey from the user-space API call to the actual execution of kernel code.
