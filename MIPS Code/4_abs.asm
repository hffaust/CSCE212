.data
  A: .word -19

.text
.globl main

main:
  la   $s0 A
  lw   $t0 0($s0)

  # Check if A is negative
  srl  $t1 $t0 31

  beq  $t1 $0 positive

  # else
  subu $t0 $0 $t0
  sw   $t0 0($s0)

  # (SPIM syscalls to print)
  or   $a0 $0 $t0
  ori  $v0 $0 1
  syscall
  ori  $a0 $0 10
  ori  $v0 $0 11
  syscall

  # exit is shared after `positive' label

positive:
  # If A is positive, exit
  ori  $v0 $0 10
  syscall

