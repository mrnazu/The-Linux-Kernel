# The Linux Kernel
- [Intro](#intro)
- [BIOS/UEFI](#biosuefi)
- [Bootloader](#bootloader)
- [Kernel Loading](#kernel-loading)
- [Kernel Initialization](#kernel-initialization)
- [User Space](#user-space)
- [The Linux Kernel API](#the-linux-kernel-api)
- [System Calls](#system-calls)
- [C Library (libc)](#c-library-libc)
- [File Descriptors](#file-descriptors)
- [Process Control](#process-control)
- [Memory Management](#memory-management)
- [Synchronization and IPC](#synchronization-and-ipc)
- [Network and Socket API](#network-and-socket-api)
- [Device Drivers](#device-drivers)
- [Virtual File System (VFS)](#virtual-file-system-vfs)
- [ioctl](#ioctl)
- [Kernel Architecture of Linux](#kernel-architecture-of-linux)
- [Commands for Hardware info](#commands-for-hardware-info)
- [Commands for Hardware Control and Config](#commands-for-hardware-control-and-config)
- [System Call Mechanics](#system-call-mechanics)
- [Real World Example with read function](#real-world-example-with-read-function)

## Intro
The Linux kernel is the core component of the Linux operating system, serving as the bridge between hardware and user-level software. It manages system resources, provides essential services, and facilitates communication between software and hardware components.

### BIOS/UEFI
When you turn on your computer, the Basic Input/Output System (BIOS) or the Unified Extensible Firmware Interface (UEFI) initializes hardware components and starts the boot process.

### Bootloader
The bootloader, such as GRUB or LILO, is responsible for locating the operating system kernel on the storage device and loading it into memory.

### Kernel Loading
The bootloader loads the Linux kernel from the storage device into the computer's RAM during the boot process.

### Kernel Initialization
The kernel initializes itself, starts essential components, initializes device drivers, and configures memory management.

### User Space
Control is transferred to the user space after the kernel is loaded and initialized, where user-level processes and applications can run.

## The Linux Kernel API
The Linux kernel provides an Application Programming Interface (API) that allows user-space programs to interact with the kernel. The API includes system calls, functions, data structures, and conventions.

### System Calls
System calls are the primary interface between user-space applications and the kernel, allowing programs to request privileged operations and access kernel services.

### C Library (libc)
The C library is an integral part of the Linux API, providing a higher-level interface for applications and wrapping low-level system calls.

### File Descriptors
File descriptors represent open files, sockets, and other I/O resources, returned by system calls like `open` and `socket`.

### Process Control
System calls related to process control enable programs to create, manage, and communicate between processes.

### Memory Management
Memory-related system calls allow programs to allocate, deallocate, and manipulate memory.

### Synchronization and IPC
System calls related to synchronization and Inter-Process Communication (IPC) facilitate communication between processes.

### Network and Socket API
The kernel provides a network API for networking-related operations, and the socket API allows applications to create, bind, and communicate over network sockets.

### Device Drivers
Device drivers provide an API for interacting with hardware devices, accessed through device files and system calls like `ioctl`.

### Virtual File System (VFS)
The Virtual File System is an abstraction layer allowing access to different file systems through a common API.

### ioctl
The `ioctl` system call is a versatile interface used for controlling various device-specific operations and configurations.

## Kernel Architecture of Linux
![Kernel Architecture](https://github.com/mrnazu/The-Linux-Kernel/assets/108541991/151b69c0-b4f7-4e57-940b-0aa1f2948cec)

Applications call functions in libc; some of those functions invoke kernel system calls, and the kernel is responsible for interacting with the hardware.

## Commands for Hardware Info
Linux provides commands for gathering information about hardware components and system configuration:

1. `lscpu`: Displays information about the CPU, including architecture and core details.
   ```bash
   lscpu
   ```

2. `lsblk`: Lists information about block devices, such as hard drives and partitions.
   ```bash
   lsblk
   ```

3. `lspci`: Provides information about PCI buses and connected devices.
   ```bash
   lspci
   ```

4. `lsusb`: Lists USB devices and related information.
   ```bash
   lsusb
   ```

5. `dmidecode`: Retrieves information from the system DMI table about hardware components.
   ```bash
   sudo dmidecode
   ```

6. `cat /proc/cpuinfo`: Displays detailed CPU information.
   ```bash
   cat /proc/cpuinfo
   ```

7. `cat /proc/meminfo`: Shows information about system memory.
   ```bash
   cat /proc/meminfo
   ```

8. `df -h`: Provides information about disk space usage on mounted filesystems.
   ```bash
   df -h
   ```

9. `free -m`: Shows information about system memory usage.
   ```bash
   free -m
   ```

10. `inxi -Fx`: A versatile command-line tool providing detailed system information.
    ```bash
    inxi -Fx
    ```



11. `hwinfo`: Command providing detailed hardware information.
    ```bash
    sudo hwinfo
    ```

12. `lshw`: Lists detailed information about hardware components.
    ```bash
    sudo lshw
    ```

## Commands for Hardware Control and Config
Controlling and configuring hardware in the Linux kernel involves using configuration files, modules, and specific tools:

1. `modprobe`: Loads and unloads kernel modules to add or remove support for hardware devices.
   ```bash
   sudo modprobe <module_name>
   ```

2. `lsmod`: Lists currently loaded kernel modules.
   ```bash
   lsmod
   ```

3. `rmmod`: Removes (unloads) a kernel module.
   ```bash
   sudo rmmod <module_name>
   ```

4. `dmesg`: Displays messages from the kernel ring buffer, providing information about hardware events.
   ```bash
   dmesg
   ```

5. `udevadm`: Controls the `udev` daemon, managing device events and providing dynamic device management.
   ```bash
   udevadm control --reload-rules
   ```

6. `lshw`: Lists detailed information about hardware components, viewing or printing configuration.
   ```bash
   sudo lshw
   ```

7. `lspci` and `lsusb`: Display information about PCI and USB devices for hardware identification.
   ```bash
   lspci
   lsusb
   ```

8. `ethtool`: Provides information about and configuration options for Ethernet devices.
   ```bash
   sudo ethtool <interface_name>
   ```

9. `hdparm`: A command-line utility to set and view ATA hard disk drive parameters.
   ```bash
   sudo hdparm -I /dev/sdX
   ```

10. `iwconfig`: Displays and allows configuration of wireless network interfaces.
    ```bash
    iwconfig
    ```

11. `sysctl`: Controls kernel parameters at runtime, tweaking various aspects of the kernel's behavior.
    ```bash
    sudo sysctl -w <parameter=value>
    ```

## System Call Mechanics
System calls are the mechanism by which user-space programs interact with the kernel. The process involves transitioning from user-space to kernel-space, executing a specific system call, and returning to user-space.

![System Call Mechanics](https://github.com/mrnazu/The-Linux-Kernel/assets/108541991/c7fbd9ce-ada3-4e8a-b9ee-4974bf53c368)

1. **User-Space to Kernel-Space Transition:**
   - Programs trigger a system call, transitioning from user mode to kernel mode.

2. **System Call Number:**
   - Each system call has a unique identifier, the system call number, used to identify the requested operation.

3. **Arguments:**
   - System calls may require additional parameters, passed as arguments.

4. **Kernel Mode Activation:**
   - The processor switches to kernel mode to execute the system call, involving an interrupt or exception.

5. **Interrupt or Exception Handling:**
   - The transition triggers an interrupt or exception, leading to execution of a designated kernel routine.

6. **System Call Table:**
   - The system call number indexes into a table of function pointers, corresponding to specific system calls.

7. **Kernel Execution:**
   - The kernel executes the requested system call, validating arguments and performing the operation.

8. **Return to User Mode:**
   - After execution, control returns to user mode, restoring the user-mode context.

9. **Return Value:**
   - The system call result is often returned to the user-space program, indicating success or failure.

## Real World Example with read function
The `read` function in C is commonly used to read data from a file descriptor. In this example, the `open` system call is used to open a file, and `read` is used to read its content.

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main() {
    int file_descriptor;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    // Open the file for reading
    file_descriptor = open("example.txt", O_RDONLY);
    
    if (file_descriptor == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read from the file
    bytesRead = read(file_descriptor, buffer, BUFFER_SIZE - 1);

    if (bytesRead == -1) {
        perror("Error reading from file");
        exit(EXIT_FAILURE);
    }

    // Null-terminate the buffer to treat it as a string
    buffer[bytesRead] = '\0';

    // Display the read content
    printf("Read from file:\n%s\n", buffer);

    // Close the file descriptor
    close(file_descriptor
In this example:

1. We use the `open` system call to open the file "example.txt" for reading (`O_RDONLY` flag).
2. The `read` system call is used to read data from the file into the `buffer`.
3. The content read from the file is then displayed using `printf`.
4. Finally, the file descriptor is closed using the `close` system call.

Compile and run this program, and you should see the content of "example.txt" displayed on the console. This is a basic example, and in a real-world scenario, you might perform more error checking and handle larger files by reading in chunks.

`gcc -o output_read read.c`
`./output_read`

---

1. **Question:**
   - In the context of the Linux kernel and system calls, what is the role of the C library (libc)? How does it facilitate communication between user-space programs and the kernel?
     
The C library (libc) serves as a high-level interface between user-space programs and the kernel. It provides a set of functions that encapsulate system calls, making it easier for developers to interact with the kernel without dealing with low-level details. The libc functions translate high-level operations into the appropriate system calls, allowing user-space programs to command the kernel, as you mentioned.
Correct! The C library (libc) serves as a high-level interface between user-space programs and the kernel. It provides a set of functions that encapsulate system calls, making it easier for developers to interact with the kernel without dealing with low-level details. The libc functions translate high-level operations into the appropriate system calls, allowing user-space programs to command the kernel, as you mentioned.

Now, let's move on to the next question:

2. **Question:**
   - In the provided C program example that reads from a file, which system call is used to open the file, and what is its purpose?

```c
file_descriptor = open("example.txt", O_RDONLY);
```

In this line, `open` is the function used to open the file "example.txt" for reading (`O_RDONLY` flag indicates read-only mode). The resulting file descriptor (`file_descriptor`) is then used with the `read` function to read data from the file.

Let's proceed to the next question:

3. **Question:**
   - What does the `read` function do in the context of the provided C program, and which system call does it correspond to in the Linux kernel?

The read function in the provided C program is used to read data from the file. It corresponds to the read system call in the Linux kernel.


---

## Reading message from the kernel
`printl` is the most commonly called function in the linux kernel.
`printk()` is the kernel's function for code to print messages. it is like C's `printf()`
The output of printk is put in a RAM buffer, and normally printed on the system console.

The Linux kernel generates various log messages that provide information about system events, errors, and other relevant details. These messages are often stored in log files, and you can use tools to view and analyze them.

One common tool for reading kernel messages is the `dmesg` command. Open a terminal and type:

```bash
dmesg
```

This command displays the kernel ring buffer, which contains messages produced by the kernel. If you want to see the latest messages, you can use the `tail` command:

```bash
dmesg | tail
```

Additionally, kernel log messages are often stored in files, such as `/var/log/kern.log` or `/var/log/messages`, depending on your Linux distribution.

## /proc, /sys and device files
`/proc` and `/sys` are special filesystems in Linux that provide a way to interact with the kernel and obtain information about the system and its devices. Device files, on the other hand, are files in the filesystem that represent devices or device drivers.

Their contents are not stored on disk. they generate their contents when you ask for it. when you `cat` a file in proc or sys, there's some corresponding functions in the kernel that's called to generate the contents. These are not RAM-based filesystems. RAM files store their contents in RAM. Virtual filesystems generate their contents when you ask for it, like `callback` function.

### `/proc` Filesystem:

1. **Purpose:**
   - The `/proc` filesystem is a virtual filesystem that provides an interface to kernel data structures. It exposes information about processes, system configuration, and kernel parameters in the form of files and directories.

2. **Example Usage:**
   - To view information about the CPU, you can navigate to `/proc/cpuinfo`.
   - To see information about memory, check `/proc/meminfo`.
   - To view a list of processes, you can look at `/proc/[PID]/` where `[PID]` is the process ID.

### `/sys` Filesystem:

1. **Purpose:**
   - Similar to `/proc`, the `/sys` filesystem is a virtual filesystem that provides an interface to kernel parameters and device configuration.

2. **Example Usage:**
   - `/sys/class`: Contains information about classes of devices.
   - `/sys/block`: Information about block devices (e.g., hard drives).
   - `/sys/bus`: Information about buses in the system (e.g., PCI, USB).
   - `/sys/devices`: Contains a hierarchical view of all devices in the system.

### Device Files:

1. **Purpose:**
   - Device files are files in the filesystem that represent devices or interfaces to devices. They allow user-space programs to communicate with device drivers and perform I/O operations.

2. **Types:**
   - **Character Devices (`/dev/tty`, `/dev/null`, etc.):** Devices that handle data as a stream of characters. Examples include terminals and serial ports.
   - **Block Devices (`/dev/sda`, `/dev/sdb`, etc.):** Devices that handle data in blocks. Examples include hard drives and SSDs.

3. **Permissions:**
   - Device files have special permissions to control access. For example, you might need special permissions to access a raw device file.

4. **Creating Device Files:**
   - Device files are usually created automatically by the system during device initialization. The `mknod` command can also be used to create device files manually.

### Examples:

1. **List Block Devices:**
   ```bash
   ls -l /sys/class/block
   ```

2. **View CPU Information:**
   ```bash
   cat /proc/cpuinfo
   ```

3. **List Devices:**
   ```bash
   ls -l /sys/class
   ```
