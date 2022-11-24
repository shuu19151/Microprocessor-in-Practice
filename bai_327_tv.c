usi8 ttl,tt_ct;
usi32 x; 
void h327_reset_tang_tcttd_if() 
{
   ttl=0; x=0; 
} 
void h327_32led_std_tsp_if() 
{ 
   if(ttl<32) 
   { 
      x=(x>>1)+0x80000000; 
      xuat_32led_don_1dw(x);
      ttl++;
   }
   else if(ttl<64)
   { 
      x=(x>>1);
      xuat_32led_don_1dw(x);
      ttl++;
   } 
   else h327_reset_tang_tcttd_if(); 
} 
void h327_32led_std_pst_if() 
{ 
   if(ttl<32) 
   { 
      x=(x<<1)+1;
      xuat_32led_don_1dw(x);
      ttl++;
 }
 else if(ttl<64) 
 { 
   x=(x<<1);
   xuat_32led_don_1dw(x);
   ttl++;
 }
   else h327_reset_tang_tcttd_if(); 
}
