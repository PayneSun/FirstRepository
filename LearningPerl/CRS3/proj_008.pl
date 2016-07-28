#! /usr/bin/perl

# July 28, 2016

use strict;
use warnings;
#use Net::Telnet;

my $IN_MODE = "file_in_mode";

print "proj_008 : ".&proj_008."\n";

#telnet cmd read or input_file read according IN_MODE
sub crs3_data_in()
{
  my $file = shift @_;
  my $cmd = shift @_;
  if($IN_MODE eq "file_in_mode")
  {
    open(IN,"$file") or die "can't open file $file:$!";
    my @contents_file = <IN>;
    close(IN);
    return @contents_file;
  }
  else
  {
    print "Error: Wrong mode.\n";
    exit 1;
  }
}

sub proj_008
{
    my @temp0 = &crs3_data_in("./proj_008.txt","show ipv4 vrf all int bri | i VPN | e unassigned");
    my %temp2 = ();    
    my $lenth = "";
    
    foreach my $str(@temp0)
    {
       if($str=~ /Up/)
       {
         chomp $str;
	 $temp2{(split(' ',$str))[4]}=0;
       }
    }

    $lenth = keys %temp2;
    print("The number is [008]  Profile Name is [IPv4 VRFs/System]  Custmer Requirement are [2000]  Nakahara LAB are [$lenth] \n"); 
    return  $lenth;
}
