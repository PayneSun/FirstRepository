#! /usr/bin/perl 

for ($i = 0; $i < @ARGV; $i++) {
   printf("%d = 0x%x\n", $ARGV[$i], $ARGV[$i]);
} 
