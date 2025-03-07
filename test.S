.section .data   // section with initialized variables 
  buffer: 
    .space 256
  message:      // (.asciz will add \0 automatically)
    .asciz "Current dir:\n"

.section .text
  .global _start

  _start:
    mov x0, #1        // file descriptor for standard output is 1
    ldr x1, =message  // load address of the variable with data to x1
    mov x2, #14       // bytes count to write
    mov x8, #64       // write system call number is 64
    svc     #0        // perform a system call

    ldr x0, =buffer   // Address of the buffer to store the current directory
    mov x1, #256      // Buffer size
    mov x8, #17       // Syscall number for getcwd
    svc     #0

    mov x0, #1        // File descriptor (stdout)
    ldr x1, =buffer   // Address of the buffer (current directory)
    mov x2, #256      // Max length
    mov x8, #64       // Syscall number for write
    svc     #0

    // exit
    mov x0, #0        // return status 0
    mov x8, #93       // exit system call is 93
    svc     #0        // perform a system cal
