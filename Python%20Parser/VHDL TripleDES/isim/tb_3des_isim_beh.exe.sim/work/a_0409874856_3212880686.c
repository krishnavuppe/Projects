/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "F:/Projects/VHDL/TripleDES/shifting.vhd";
extern char *IEEE_P_3620187407;
extern char *IEEE_P_2592010699;



static void work_a_0409874856_3212880686_p_0(char *t0)
{
    char t8[16];
    char t17[16];
    char t25[16];
    char t33[16];
    char t49[16];
    char t51[16];
    unsigned char t1;
    unsigned char t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    int t11;
    unsigned int t12;
    unsigned char t13;
    char *t14;
    char *t15;
    char *t16;
    char *t18;
    char *t19;
    int t20;
    unsigned char t21;
    char *t22;
    char *t23;
    char *t24;
    char *t26;
    char *t27;
    int t28;
    unsigned char t29;
    char *t30;
    char *t31;
    char *t34;
    char *t35;
    int t36;
    unsigned char t37;
    char *t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    char *t42;
    int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned char t47;
    char *t48;
    char *t50;
    char *t52;
    char *t53;
    int t54;
    unsigned int t55;
    unsigned char t56;
    char *t57;
    char *t58;
    char *t59;
    char *t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;

LAB0:    xsi_set_current_line(31, ng0);
    t4 = (t0 + 1672U);
    t5 = *((char **)t4);
    t4 = (t0 + 5008U);
    t6 = (t0 + 5092);
    t9 = (t8 + 0U);
    t10 = (t9 + 0U);
    *((int *)t10) = 0;
    t10 = (t9 + 4U);
    *((int *)t10) = 3;
    t10 = (t9 + 8U);
    *((int *)t10) = 1;
    t11 = (3 - 0);
    t12 = (t11 * 1);
    t12 = (t12 + 1);
    t10 = (t9 + 12U);
    *((unsigned int *)t10) = t12;
    t13 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t5, t4, t6, t8);
    if (t13 == 1)
        goto LAB11;

LAB12:    t10 = (t0 + 1672U);
    t14 = *((char **)t10);
    t10 = (t0 + 5008U);
    t15 = (t0 + 5096);
    t18 = (t17 + 0U);
    t19 = (t18 + 0U);
    *((int *)t19) = 0;
    t19 = (t18 + 4U);
    *((int *)t19) = 3;
    t19 = (t18 + 8U);
    *((int *)t19) = 1;
    t20 = (3 - 0);
    t12 = (t20 * 1);
    t12 = (t12 + 1);
    t19 = (t18 + 12U);
    *((unsigned int *)t19) = t12;
    t21 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t14, t10, t15, t17);
    t3 = t21;

LAB13:    if (t3 == 1)
        goto LAB8;

LAB9:    t19 = (t0 + 1672U);
    t22 = *((char **)t19);
    t19 = (t0 + 5008U);
    t23 = (t0 + 5100);
    t26 = (t25 + 0U);
    t27 = (t26 + 0U);
    *((int *)t27) = 0;
    t27 = (t26 + 4U);
    *((int *)t27) = 3;
    t27 = (t26 + 8U);
    *((int *)t27) = 1;
    t28 = (3 - 0);
    t12 = (t28 * 1);
    t12 = (t12 + 1);
    t27 = (t26 + 12U);
    *((unsigned int *)t27) = t12;
    t29 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t22, t19, t23, t25);
    t2 = t29;

LAB10:    if (t2 == 1)
        goto LAB5;

LAB6:    t27 = (t0 + 1672U);
    t30 = *((char **)t27);
    t27 = (t0 + 5008U);
    t31 = (t0 + 5104);
    t34 = (t33 + 0U);
    t35 = (t34 + 0U);
    *((int *)t35) = 0;
    t35 = (t34 + 4U);
    *((int *)t35) = 3;
    t35 = (t34 + 8U);
    *((int *)t35) = 1;
    t36 = (3 - 0);
    t12 = (t36 * 1);
    t12 = (t12 + 1);
    t35 = (t34 + 12U);
    *((unsigned int *)t35) = t12;
    t37 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t30, t27, t31, t33);
    t1 = t37;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:    xsi_set_current_line(35, ng0);
    t4 = (t0 + 1032U);
    t5 = *((char **)t4);
    t12 = (27 - 25);
    t39 = (t12 * 1U);
    t40 = (0 + t39);
    t4 = (t5 + t40);
    t6 = (t0 + 1032U);
    t7 = *((char **)t6);
    t11 = (27 - 27);
    t44 = (t11 * -1);
    t45 = (1U * t44);
    t46 = (0 + t45);
    t6 = (t7 + t46);
    t1 = *((unsigned char *)t6);
    t10 = ((IEEE_P_2592010699) + 4024);
    t14 = (t17 + 0U);
    t15 = (t14 + 0U);
    *((int *)t15) = 25;
    t15 = (t14 + 4U);
    *((int *)t15) = 0;
    t15 = (t14 + 8U);
    *((int *)t15) = -1;
    t20 = (0 - 25);
    t55 = (t20 * -1);
    t55 = (t55 + 1);
    t15 = (t14 + 12U);
    *((unsigned int *)t15) = t55;
    t9 = xsi_base_array_concat(t9, t8, t10, (char)97, t4, t17, (char)99, t1, (char)101);
    t15 = (t0 + 1032U);
    t16 = *((char **)t15);
    t28 = (26 - 27);
    t55 = (t28 * -1);
    t61 = (1U * t55);
    t62 = (0 + t61);
    t15 = (t16 + t62);
    t2 = *((unsigned char *)t15);
    t19 = ((IEEE_P_2592010699) + 4024);
    t18 = xsi_base_array_concat(t18, t25, t19, (char)97, t9, t8, (char)99, t2, (char)101);
    t63 = (26U + 1U);
    t64 = (t63 + 1U);
    t3 = (28U != t64);
    if (t3 == 1)
        goto LAB18;

LAB19:    t22 = (t0 + 3232);
    t23 = (t22 + 56U);
    t24 = *((char **)t23);
    t26 = (t24 + 56U);
    t27 = *((char **)t26);
    memcpy(t27, t18, 28U);
    xsi_driver_first_trans_fast_port(t22);
    xsi_set_current_line(36, ng0);
    t4 = (t0 + 1192U);
    t5 = *((char **)t4);
    t12 = (27 - 25);
    t39 = (t12 * 1U);
    t40 = (0 + t39);
    t4 = (t5 + t40);
    t6 = (t0 + 1192U);
    t7 = *((char **)t6);
    t11 = (27 - 27);
    t44 = (t11 * -1);
    t45 = (1U * t44);
    t46 = (0 + t45);
    t6 = (t7 + t46);
    t1 = *((unsigned char *)t6);
    t10 = ((IEEE_P_2592010699) + 4024);
    t14 = (t17 + 0U);
    t15 = (t14 + 0U);
    *((int *)t15) = 25;
    t15 = (t14 + 4U);
    *((int *)t15) = 0;
    t15 = (t14 + 8U);
    *((int *)t15) = -1;
    t20 = (0 - 25);
    t55 = (t20 * -1);
    t55 = (t55 + 1);
    t15 = (t14 + 12U);
    *((unsigned int *)t15) = t55;
    t9 = xsi_base_array_concat(t9, t8, t10, (char)97, t4, t17, (char)99, t1, (char)101);
    t15 = (t0 + 1192U);
    t16 = *((char **)t15);
    t28 = (26 - 27);
    t55 = (t28 * -1);
    t61 = (1U * t55);
    t62 = (0 + t61);
    t15 = (t16 + t62);
    t2 = *((unsigned char *)t15);
    t19 = ((IEEE_P_2592010699) + 4024);
    t18 = xsi_base_array_concat(t18, t25, t19, (char)97, t9, t8, (char)99, t2, (char)101);
    t63 = (26U + 1U);
    t64 = (t63 + 1U);
    t3 = (28U != t64);
    if (t3 == 1)
        goto LAB20;

LAB21:    t22 = (t0 + 3296);
    t23 = (t22 + 56U);
    t24 = *((char **)t23);
    t26 = (t24 + 56U);
    t27 = *((char **)t26);
    memcpy(t27, t18, 28U);
    xsi_driver_first_trans_fast_port(t22);

LAB3:    t4 = (t0 + 3152);
    *((int *)t4) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(32, ng0);
    t35 = (t0 + 1032U);
    t38 = *((char **)t35);
    t12 = (27 - 26);
    t39 = (t12 * 1U);
    t40 = (0 + t39);
    t35 = (t38 + t40);
    t41 = (t0 + 1032U);
    t42 = *((char **)t41);
    t43 = (27 - 27);
    t44 = (t43 * -1);
    t45 = (1U * t44);
    t46 = (0 + t45);
    t41 = (t42 + t46);
    t47 = *((unsigned char *)t41);
    t50 = ((IEEE_P_2592010699) + 4024);
    t52 = (t51 + 0U);
    t53 = (t52 + 0U);
    *((int *)t53) = 26;
    t53 = (t52 + 4U);
    *((int *)t53) = 0;
    t53 = (t52 + 8U);
    *((int *)t53) = -1;
    t54 = (0 - 26);
    t55 = (t54 * -1);
    t55 = (t55 + 1);
    t53 = (t52 + 12U);
    *((unsigned int *)t53) = t55;
    t48 = xsi_base_array_concat(t48, t49, t50, (char)97, t35, t51, (char)99, t47, (char)101);
    t55 = (27U + 1U);
    t56 = (28U != t55);
    if (t56 == 1)
        goto LAB14;

LAB15:    t53 = (t0 + 3232);
    t57 = (t53 + 56U);
    t58 = *((char **)t57);
    t59 = (t58 + 56U);
    t60 = *((char **)t59);
    memcpy(t60, t48, 28U);
    xsi_driver_first_trans_fast_port(t53);
    xsi_set_current_line(33, ng0);
    t4 = (t0 + 1192U);
    t5 = *((char **)t4);
    t12 = (27 - 26);
    t39 = (t12 * 1U);
    t40 = (0 + t39);
    t4 = (t5 + t40);
    t6 = (t0 + 1192U);
    t7 = *((char **)t6);
    t11 = (27 - 27);
    t44 = (t11 * -1);
    t45 = (1U * t44);
    t46 = (0 + t45);
    t6 = (t7 + t46);
    t1 = *((unsigned char *)t6);
    t10 = ((IEEE_P_2592010699) + 4024);
    t14 = (t17 + 0U);
    t15 = (t14 + 0U);
    *((int *)t15) = 26;
    t15 = (t14 + 4U);
    *((int *)t15) = 0;
    t15 = (t14 + 8U);
    *((int *)t15) = -1;
    t20 = (0 - 26);
    t55 = (t20 * -1);
    t55 = (t55 + 1);
    t15 = (t14 + 12U);
    *((unsigned int *)t15) = t55;
    t9 = xsi_base_array_concat(t9, t8, t10, (char)97, t4, t17, (char)99, t1, (char)101);
    t55 = (27U + 1U);
    t2 = (28U != t55);
    if (t2 == 1)
        goto LAB16;

LAB17:    t15 = (t0 + 3296);
    t16 = (t15 + 56U);
    t18 = *((char **)t16);
    t19 = (t18 + 56U);
    t22 = *((char **)t19);
    memcpy(t22, t9, 28U);
    xsi_driver_first_trans_fast_port(t15);
    goto LAB3;

LAB5:    t1 = (unsigned char)1;
    goto LAB7;

LAB8:    t2 = (unsigned char)1;
    goto LAB10;

LAB11:    t3 = (unsigned char)1;
    goto LAB13;

LAB14:    xsi_size_not_matching(28U, t55, 0);
    goto LAB15;

LAB16:    xsi_size_not_matching(28U, t55, 0);
    goto LAB17;

LAB18:    xsi_size_not_matching(28U, t64, 0);
    goto LAB19;

LAB20:    xsi_size_not_matching(28U, t64, 0);
    goto LAB21;

}


extern void work_a_0409874856_3212880686_init()
{
	static char *pe[] = {(void *)work_a_0409874856_3212880686_p_0};
	xsi_register_didat("work_a_0409874856_3212880686", "isim/tb_3des_isim_beh.exe.sim/work/a_0409874856_3212880686.didat");
	xsi_register_executes(pe);
}
