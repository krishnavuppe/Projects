
module block32 ( result, cout6, cout7, cout14, cout15, cout30, cout31, a_var, b_var, var_code, anl, cin );
  output [31:0] result;
  input [31:0] a_var;
  input [31:0] b_var;
  input [3:0] var_code;
  input anl, cin;
  output cout6, cout7, cout14, cout15, cout30, cout31;
  wire   n233, n234, n235, n236, n237, n238, n239, n240, n241, n242, n243,
         n244, n245, n246, n247, n248, n249, n250, n251, n252, n253, n254,
         n255, n256, n257, n258, n259, n260, n261, n262, n263, n264, n265,
         n266, n267, n268, n269, n270, n271, n272, n273, n274, n275, n276,
         n277, n278, n279, n280, n281, n282, n283, n284, n285, n286, n287,
         n288, n289, n290, n291, n292, n293, n294, n295, n296, n297, n298,
         n299, n300, n301, n302, n303, n304, n305, n306, n307, n308, n309,
         n310, n311, n312, n313, n314, n315, n316, n317, n318, n319, n320,
         n321, n322, n323, n324, n325, n326, n327, n328, n329, n330, n331,
         n332, n333, n334, n335, n336, n337, n338, n339, n340, n341, n342,
         n343, n344, n345, n346, n347, n348, n349, n350, n351, n352, n353,
         n354, n355, n356, n357, n358, n359, n360, n361, n362, n363, n364,
         n365, n366, n367, n368, n369, n370, n371, n372, n373, n374, n375,
         n376, n377, n378, n379, n380, n381, n382, n383, n384, n385, n386,
         n387, n388, n389, n390, n391, n392, n393, n394, n395, n396, n397,
         n398, n399, n400, n401, n402, n403, n404, n405, n406, n407, n408,
         n409, n410, n411, n412, n413, n414, n415, n416, n417, n418, n419,
         n420, n421, n422, n423, n424, n425, n426, n427, n428, n429, n430,
         n431, n432, n433, n434, n435, n436, n437, n438, n439, n440, n441,
         n442, n443, n444, n445, n446, n447, n448, n449, n450, n451, n452,
         n453, n454, n455, n456, n457, n458, n459, n460, n461, n462, n463,
         n464, n465, n466, n467, n468, n469, n470, n471, n472, n473, n474,
         n475, n476, n477, n478, n479, n480, n481, n482, n483, n484, n485,
         n486, n487, n488, n489, n490, n491, n492, n493, n494, n495;

  NAND3XL U270 ( .A(n394), .B(n395), .C(n396), .Y(n233) );
  NAND2X1 U271 ( .A(n233), .B(n397), .Y(n403) );
  CLKINVX1 U272 ( .A(b_var[15]), .Y(n234) );
  OAI22XL U273 ( .A0(b_var[15]), .A1(n462), .B0(n234), .B1(n461), .Y(n235) );
  OAI221X1 U274 ( .A0(b_var[15]), .A1(n464), .B0(n234), .B1(n463), .C0(a_var[15]), .Y(n236) );
  OAI21XL U275 ( .A0(n235), .A1(a_var[15]), .B0(n236), .Y(n326) );
  OAI2BB1X1 U276 ( .A0N(anl), .A1N(b_var[25]), .B0(n414), .Y(n237) );
  OAI211XL U277 ( .A0(n414), .A1(n410), .B0(n409), .C0(n237), .Y(n417) );
  CLKINVX1 U278 ( .A(b_var[1]), .Y(n238) );
  OAI22XL U279 ( .A0(b_var[1]), .A1(var_code[0]), .B0(n238), .B1(var_code[1]), .Y(n239) );
  OAI221X1 U280 ( .A0(b_var[1]), .A1(var_code[2]), .B0(n238), .B1(var_code[3]), .C0(a_var[1]), .Y(n240) );
  OAI21XL U281 ( .A0(n239), .A1(a_var[1]), .B0(n240), .Y(n360) );
  CLKINVX1 U282 ( .A(b_var[26]), .Y(n241) );
  OAI22XL U283 ( .A0(b_var[26]), .A1(n462), .B0(n241), .B1(n461), .Y(n242) );
  OAI221X1 U284 ( .A0(b_var[26]), .A1(n464), .B0(n241), .B1(n463), .C0(a_var[26]), .Y(n243) );
  OAI21XL U285 ( .A0(n242), .A1(a_var[26]), .B0(n243), .Y(n423) );
  NOR2XL U286 ( .A(n484), .B(n483), .Y(n244) );
  OAI33X1 U287 ( .A0(n287), .A1(n493), .A2(n286), .B0(n485), .B1(n244), .B2(n482), .Y(cout7) );
  CLKINVX1 U288 ( .A(b_var[10]), .Y(n245) );
  OAI22XL U289 ( .A0(b_var[10]), .A1(var_code[0]), .B0(n245), .B1(var_code[1]), .Y(n246) );
  OAI221X1 U290 ( .A0(b_var[10]), .A1(var_code[2]), .B0(n245), .B1(var_code[3]), .C0(a_var[10]), .Y(n247) );
  OAI21XL U291 ( .A0(n246), .A1(a_var[10]), .B0(n247), .Y(n291) );
  CLKINVX1 U292 ( .A(b_var[11]), .Y(n248) );
  OAI22XL U293 ( .A0(b_var[11]), .A1(var_code[0]), .B0(n248), .B1(var_code[1]), .Y(n249) );
  OAI221X1 U294 ( .A0(b_var[11]), .A1(var_code[2]), .B0(n248), .B1(var_code[3]), .C0(a_var[11]), .Y(n250) );
  OAI21XL U295 ( .A0(n249), .A1(a_var[11]), .B0(n250), .Y(n296) );
  OAI21XL U296 ( .A0(cin), .A1(n495), .B0(n359), .Y(n251) );
  XNOR2XL U297 ( .A(n360), .B(n251), .Y(result[1]) );
  AOI32X1 U298 ( .A0(n349), .A1(n339), .A2(n350), .B0(n336), .B1(n339), .Y(result[17]) );
  OAI21XL U299 ( .A0(n400), .A1(n403), .B0(n405), .Y(n252) );
  XNOR2XL U300 ( .A(n406), .B(n252), .Y(result[24]) );
  AOI32X1 U301 ( .A0(n448), .A1(n435), .A2(n449), .B0(n432), .B1(n435), .Y(result[28]) );
  OAI32X1 U302 ( .A0(n494), .A1(n493), .A2(n492), .B0(n491), .B1(n490), .Y(cout31) );
  INVX2 U303 ( .A(n457), .Y(result[30]) );
  OAI21XL U304 ( .A0(n440), .A1(n455), .B0(n439), .Y(result[29]) );
  NAND2X1 U305 ( .A(n440), .B(n455), .Y(n439) );
  NAND2X1 U306 ( .A(n435), .B(n434), .Y(n440) );
  OAI31X1 U307 ( .A0(n431), .A1(n429), .A2(n428), .B0(n424), .Y(result[27]) );
  NAND2X1 U308 ( .A(n416), .B(n423), .Y(n415) );
  NAND2X1 U309 ( .A(n417), .B(n422), .Y(n416) );
  INVX2 U310 ( .A(n414), .Y(n408) );
  OAI21XL U311 ( .A0(n389), .A1(n396), .B0(n388), .Y(result[23]) );
  NAND2X1 U312 ( .A(n389), .B(n396), .Y(n388) );
  OAI21XL U313 ( .A0(n379), .A1(n409), .B0(n381), .Y(n380) );
  INVX2 U314 ( .A(n409), .Y(n400) );
  INVX2 U315 ( .A(n368), .Y(result[20]) );
  INVX2 U316 ( .A(n358), .Y(result[19]) );
  OAI21XL U317 ( .A0(n344), .A1(n356), .B0(n343), .Y(result[18]) );
  NAND2X1 U318 ( .A(n344), .B(n356), .Y(n343) );
  NAND2X1 U319 ( .A(n339), .B(n338), .Y(n344) );
  OAI2BB2X1 U320 ( .B0(n333), .B1(cout15), .A0N(n333), .A1N(cout15), .Y(result[16]) );
  OAI2BB2X1 U321 ( .B0(n326), .B1(cout14), .A0N(n326), .A1N(cout14), .Y(result[15]) );
  NAND2X1 U322 ( .A(n316), .B(n322), .Y(n315) );
  OAI21XL U323 ( .A0(a_var[31]), .A1(n466), .B0(n465), .Y(n490) );
  INVX2 U324 ( .A(cout30), .Y(n491) );
  OAI2BB2X1 U325 ( .B0(n306), .B1(n307), .A0N(n306), .A1N(n307), .Y(result[12]) );
  OAI21XL U326 ( .A0(n291), .A1(n290), .B0(n292), .Y(result[10]) );
  AOI21X1 U327 ( .A0(n489), .A1(n488), .B0(n487), .Y(result[9]) );
  OAI2BB2X1 U328 ( .B0(cout7), .B1(n486), .A0N(cout7), .A1N(n486), .Y(result[8]) );
  NAND2X1 U329 ( .A(n477), .B(n476), .Y(n479) );
  AOI31X1 U330 ( .A0(n477), .A1(n475), .A2(n478), .B0(n474), .Y(n480) );
  INVX2 U331 ( .A(n475), .Y(n476) );
  AOI21X1 U332 ( .A0(n472), .A1(n471), .B0(n470), .Y(result[4]) );
  AOI21X1 U333 ( .A0(n469), .A1(n468), .B0(n467), .Y(result[3]) );
  OAI21XL U334 ( .A0(n443), .A1(n442), .B0(n441), .Y(result[2]) );
  OAI2BB2X1 U335 ( .B0(n495), .B1(cin), .A0N(n495), .A1N(cin), .Y(result[0]) );
  OAI21XL U336 ( .A0(n455), .A1(n454), .B0(n453), .Y(n456) );
  NAND2X1 U337 ( .A(n431), .B(n430), .Y(n449) );
  NAND2X1 U338 ( .A(n374), .B(n367), .Y(n372) );
  NAND2X1 U339 ( .A(n366), .B(n357), .Y(n364) );
  NAND2X1 U340 ( .A(n335), .B(n334), .Y(n350) );
  NOR3XL U341 ( .A(n309), .B(n308), .C(n307), .Y(n321) );
  INVX2 U342 ( .A(n477), .Y(n473) );
  OAI21XL U343 ( .A0(a_var[2]), .A1(n283), .B0(n282), .Y(n442) );
  OAI2BB1X1 U344 ( .A0N(b_var[0]), .A1N(n495), .B0(n360), .Y(n278) );
  OAI21XL U345 ( .A0(n277), .A1(n493), .B0(n495), .Y(n359) );
  OAI21XL U346 ( .A0(a_var[0]), .A1(n276), .B0(n275), .Y(n495) );
  OAI21XL U347 ( .A0(a_var[3]), .A1(n274), .B0(n273), .Y(n468) );
  OAI21XL U348 ( .A0(a_var[4]), .A1(n271), .B0(n270), .Y(n471) );
  OAI22XL U349 ( .A0(a_var[5]), .A1(n266), .B0(n265), .B1(n264), .Y(n477) );
  OAI22XL U350 ( .A0(a_var[6]), .A1(n263), .B0(n262), .B1(n261), .Y(n284) );
  OAI22XL U351 ( .A0(a_var[7]), .A1(n260), .B0(n259), .B1(n258), .Y(n287) );
  OAI22XL U352 ( .A0(b_var[7]), .A1(var_code[2]), .B0(n286), .B1(var_code[3]), .Y(n258) );
  OAI22XL U353 ( .A0(b_var[7]), .A1(var_code[0]), .B0(n286), .B1(var_code[1]), .Y(n260) );
  OAI21XL U354 ( .A0(a_var[8]), .A1(n257), .B0(n256), .Y(n486) );
  OAI22XL U355 ( .A0(b_var[8]), .A1(n462), .B0(n288), .B1(n461), .Y(n257) );
  OAI21XL U356 ( .A0(a_var[9]), .A1(n255), .B0(n254), .Y(n488) );
  INVX2 U357 ( .A(n312), .Y(n302) );
  OAI21XL U358 ( .A0(n326), .A1(n325), .B0(n324), .Y(n332) );
  OAI21XL U359 ( .A0(n320), .A1(n319), .B0(n318), .Y(n325) );
  OAI21XL U360 ( .A0(a_var[14]), .A1(n314), .B0(n313), .Y(n319) );
  OAI22XL U361 ( .A0(b_var[14]), .A1(n462), .B0(n317), .B1(n461), .Y(n314) );
  OAI21XL U362 ( .A0(a_var[12]), .A1(n295), .B0(n294), .Y(n300) );
  OAI22XL U363 ( .A0(b_var[12]), .A1(n462), .B0(n304), .B1(n461), .Y(n295) );
  OAI21XL U364 ( .A0(a_var[13]), .A1(n299), .B0(n298), .Y(n312) );
  OAI22XL U365 ( .A0(b_var[13]), .A1(n462), .B0(n303), .B1(n461), .Y(n299) );
  OAI21XL U366 ( .A0(a_var[16]), .A1(n328), .B0(n327), .Y(n333) );
  OAI21XL U367 ( .A0(a_var[17]), .A1(n330), .B0(n329), .Y(n351) );
  OAI21XL U368 ( .A0(a_var[18]), .A1(n342), .B0(n341), .Y(n356) );
  OAI22XL U369 ( .A0(a_var[19]), .A1(n347), .B0(n346), .B1(n345), .Y(n366) );
  OAI22XL U370 ( .A0(a_var[20]), .A1(n363), .B0(n362), .B1(n361), .Y(n374) );
  OAI21XL U371 ( .A0(n423), .A1(n422), .B0(n421), .Y(n428) );
  INVX2 U372 ( .A(n382), .Y(n383) );
  NAND2X1 U373 ( .A(n382), .B(n381), .Y(n394) );
  OAI21XL U374 ( .A0(n378), .A1(n493), .B0(n379), .Y(n381) );
  OAI21XL U375 ( .A0(a_var[22]), .A1(n377), .B0(n376), .Y(n382) );
  OAI22XL U376 ( .A0(b_var[22]), .A1(var_code[0]), .B0(n375), .B1(var_code[1]), .Y(n377) );
  OAI22XL U377 ( .A0(a_var[21]), .A1(n371), .B0(n370), .B1(n369), .Y(n384) );
  OAI22XL U378 ( .A0(a_var[23]), .A1(n387), .B0(n386), .B1(n385), .Y(n399) );
  OAI21XL U379 ( .A0(a_var[24]), .A1(n392), .B0(n391), .Y(n406) );
  OAI22XL U380 ( .A0(b_var[24]), .A1(n462), .B0(n390), .B1(n461), .Y(n392) );
  OAI21XL U381 ( .A0(a_var[25]), .A1(n402), .B0(n401), .Y(n414) );
  OAI22XL U382 ( .A0(b_var[25]), .A1(n462), .B0(n411), .B1(n461), .Y(n402) );
  OAI22XL U383 ( .A0(a_var[27]), .A1(n420), .B0(n419), .B1(n418), .Y(n429) );
  OAI21XL U384 ( .A0(a_var[28]), .A1(n426), .B0(n425), .Y(n450) );
  INVX2 U385 ( .A(var_code[3]), .Y(n463) );
  INVX2 U386 ( .A(var_code[2]), .Y(n464) );
  INVX2 U387 ( .A(var_code[1]), .Y(n461) );
  INVX2 U388 ( .A(var_code[0]), .Y(n462) );
  OAI21XL U389 ( .A0(a_var[29]), .A1(n438), .B0(n437), .Y(n455) );
  INVX2 U390 ( .A(anl), .Y(n493) );
  OAI22XL U391 ( .A0(a_var[30]), .A1(n446), .B0(n445), .B1(n444), .Y(n460) );
  INVX2 U392 ( .A(n450), .Y(n432) );
  AOI21X1 U393 ( .A0(n410), .A1(n409), .B0(n413), .Y(n407) );
  AOI2BB1X1 U394 ( .A0N(n394), .A1N(n400), .B0(n398), .Y(n389) );
  INVX2 U395 ( .A(n351), .Y(n336) );
  INVX2 U396 ( .A(n490), .Y(n494) );
  OAI221X1 U397 ( .A0(b_var[31]), .A1(n464), .B0(n492), .B1(n463), .C0(
        a_var[31]), .Y(n465) );
  INVX2 U398 ( .A(b_var[31]), .Y(n492) );
  OAI2BB2X1 U399 ( .B0(n485), .B1(cout6), .A0N(n485), .A1N(cout6), .Y(
        result[7]) );
  AOI32X1 U400 ( .A0(n481), .A1(n480), .A2(n479), .B0(n478), .B1(n480), .Y(
        result[6]) );
  AOI2BB1X1 U401 ( .A0N(n484), .A1N(n483), .B0(n482), .Y(cout6) );
  NAND2X1 U402 ( .A(n325), .B(n323), .Y(cout14) );
  OR2X2 U403 ( .A(n335), .B(n332), .Y(cout15) );
  OAI31X1 U404 ( .A0(n460), .A1(n459), .A2(n493), .B0(n458), .Y(cout30) );
  NAND2X1 U405 ( .A(n460), .B(n456), .Y(n458) );
  OAI31X1 U406 ( .A0(n374), .A1(n373), .A2(n493), .B0(n372), .Y(n409) );
  OAI31X1 U407 ( .A0(n366), .A1(n365), .A2(n493), .B0(n364), .Y(n367) );
  NAND2X1 U408 ( .A(n322), .B(n321), .Y(n323) );
  AOI32X1 U409 ( .A0(b_var[11]), .A1(n297), .A2(anl), .B0(n296), .B1(n297), 
        .Y(n307) );
  NAND2X1 U410 ( .A(n296), .B(n293), .Y(n297) );
  AOI32X1 U411 ( .A0(b_var[10]), .A1(n292), .A2(anl), .B0(n291), .B1(n292), 
        .Y(n293) );
  NAND2X1 U412 ( .A(n291), .B(n290), .Y(n292) );
  AOI31X1 U413 ( .A0(b_var[9]), .A1(anl), .A2(n488), .B0(n487), .Y(n290) );
  INVX2 U414 ( .A(n287), .Y(n485) );
  AOI2BB1X1 U415 ( .A0N(n493), .A1N(n285), .B0(n478), .Y(n482) );
  NAND2X1 U416 ( .A(n478), .B(n481), .Y(n483) );
  INVX2 U417 ( .A(n284), .Y(n478) );
  AOI31X1 U418 ( .A0(b_var[4]), .A1(anl), .A2(n471), .B0(n470), .Y(n475) );
  AOI31X1 U419 ( .A0(b_var[3]), .A1(anl), .A2(n468), .B0(n467), .Y(n472) );
  AOI32X1 U420 ( .A0(b_var[2]), .A1(n441), .A2(anl), .B0(n442), .B1(n441), .Y(
        n469) );
  NAND2X1 U421 ( .A(n443), .B(n442), .Y(n441) );
  OAI221X1 U422 ( .A0(b_var[2]), .A1(var_code[2]), .B0(n281), .B1(
        var_code[3]), .C0(a_var[2]), .Y(n282) );
  INVX2 U423 ( .A(b_var[2]), .Y(n281) );
  AOI31X1 U424 ( .A0(n360), .A1(cin), .A2(n359), .B0(n280), .Y(n443) );
  OAI221X1 U425 ( .A0(b_var[0]), .A1(n464), .B0(n277), .B1(n463), .C0(a_var[0]), .Y(n275) );
  INVX2 U426 ( .A(b_var[0]), .Y(n277) );
  OAI221X1 U427 ( .A0(b_var[3]), .A1(n464), .B0(n272), .B1(n463), .C0(a_var[3]), .Y(n273) );
  INVX2 U428 ( .A(b_var[3]), .Y(n272) );
  OAI221X1 U429 ( .A0(b_var[4]), .A1(n464), .B0(n269), .B1(n463), .C0(a_var[4]), .Y(n270) );
  INVX2 U430 ( .A(b_var[4]), .Y(n269) );
  INVX2 U431 ( .A(a_var[5]), .Y(n265) );
  INVX2 U432 ( .A(b_var[5]), .Y(n267) );
  INVX2 U433 ( .A(a_var[6]), .Y(n262) );
  INVX2 U434 ( .A(a_var[7]), .Y(n259) );
  INVX2 U435 ( .A(b_var[7]), .Y(n286) );
  OAI221X1 U436 ( .A0(b_var[8]), .A1(n464), .B0(n288), .B1(n463), .C0(a_var[8]), .Y(n256) );
  INVX2 U437 ( .A(b_var[8]), .Y(n288) );
  OAI221X1 U438 ( .A0(b_var[9]), .A1(n464), .B0(n253), .B1(n463), .C0(a_var[9]), .Y(n254) );
  INVX2 U439 ( .A(b_var[9]), .Y(n253) );
  INVX2 U440 ( .A(n300), .Y(n306) );
  AOI2BB1X1 U441 ( .A0N(n303), .A1N(n493), .B0(n302), .Y(n309) );
  INVX2 U442 ( .A(n319), .Y(n322) );
  OAI221X1 U443 ( .A0(b_var[14]), .A1(n464), .B0(n317), .B1(n463), .C0(
        a_var[14]), .Y(n313) );
  INVX2 U444 ( .A(b_var[14]), .Y(n317) );
  OAI221X1 U445 ( .A0(b_var[12]), .A1(n464), .B0(n304), .B1(n463), .C0(
        a_var[12]), .Y(n294) );
  INVX2 U446 ( .A(b_var[12]), .Y(n304) );
  OAI221X1 U447 ( .A0(b_var[13]), .A1(n464), .B0(n303), .B1(n463), .C0(
        a_var[13]), .Y(n298) );
  INVX2 U448 ( .A(b_var[13]), .Y(n303) );
  OAI221X1 U449 ( .A0(b_var[16]), .A1(n464), .B0(n331), .B1(n463), .C0(
        a_var[16]), .Y(n327) );
  INVX2 U450 ( .A(b_var[16]), .Y(n331) );
  OAI221X1 U451 ( .A0(b_var[17]), .A1(n464), .B0(n337), .B1(n463), .C0(
        a_var[17]), .Y(n329) );
  INVX2 U452 ( .A(b_var[17]), .Y(n337) );
  NAND2X1 U453 ( .A(anl), .B(b_var[18]), .Y(n355) );
  OAI221X1 U454 ( .A0(b_var[18]), .A1(var_code[2]), .B0(n340), .B1(
        var_code[3]), .C0(a_var[18]), .Y(n341) );
  INVX2 U455 ( .A(b_var[18]), .Y(n340) );
  INVX2 U456 ( .A(a_var[19]), .Y(n346) );
  INVX2 U457 ( .A(b_var[19]), .Y(n365) );
  INVX2 U458 ( .A(a_var[20]), .Y(n362) );
  INVX2 U459 ( .A(n399), .Y(n396) );
  INVX2 U460 ( .A(n384), .Y(n379) );
  OAI221X1 U461 ( .A0(b_var[22]), .A1(var_code[2]), .B0(n375), .B1(
        var_code[3]), .C0(a_var[22]), .Y(n376) );
  INVX2 U462 ( .A(b_var[22]), .Y(n375) );
  INVX2 U463 ( .A(a_var[21]), .Y(n370) );
  INVX2 U464 ( .A(b_var[21]), .Y(n378) );
  INVX2 U465 ( .A(a_var[23]), .Y(n386) );
  INVX2 U466 ( .A(b_var[23]), .Y(n393) );
  OAI221X1 U467 ( .A0(b_var[24]), .A1(n464), .B0(n390), .B1(n463), .C0(
        a_var[24]), .Y(n391) );
  INVX2 U468 ( .A(b_var[24]), .Y(n390) );
  OAI221X1 U469 ( .A0(b_var[25]), .A1(n464), .B0(n411), .B1(n463), .C0(
        a_var[25]), .Y(n401) );
  INVX2 U470 ( .A(b_var[25]), .Y(n411) );
  INVX2 U471 ( .A(a_var[27]), .Y(n419) );
  INVX2 U472 ( .A(b_var[27]), .Y(n427) );
  OAI221X1 U473 ( .A0(b_var[28]), .A1(n464), .B0(n433), .B1(n463), .C0(
        a_var[28]), .Y(n425) );
  INVX2 U474 ( .A(b_var[28]), .Y(n433) );
  NAND2X1 U475 ( .A(anl), .B(b_var[29]), .Y(n454) );
  OAI221X1 U476 ( .A0(b_var[29]), .A1(var_code[2]), .B0(n436), .B1(
        var_code[3]), .C0(a_var[29]), .Y(n437) );
  INVX2 U477 ( .A(b_var[29]), .Y(n436) );
  INVX2 U478 ( .A(a_var[30]), .Y(n445) );
  INVX2 U479 ( .A(b_var[6]), .Y(n285) );
  INVX2 U480 ( .A(b_var[20]), .Y(n373) );
  INVX2 U481 ( .A(b_var[30]), .Y(n459) );
  OAI22XL U482 ( .A0(b_var[9]), .A1(n462), .B0(n253), .B1(n461), .Y(n255) );
  OAI22XL U483 ( .A0(b_var[6]), .A1(n462), .B0(n285), .B1(n461), .Y(n263) );
  OAI22XL U484 ( .A0(b_var[6]), .A1(n464), .B0(n285), .B1(n463), .Y(n261) );
  OAI22XL U485 ( .A0(b_var[5]), .A1(var_code[0]), .B0(n267), .B1(
        var_code[1]), .Y(n266) );
  OAI22XL U486 ( .A0(b_var[5]), .A1(var_code[2]), .B0(n267), .B1(
        var_code[3]), .Y(n264) );
  NOR2XL U487 ( .A(n493), .B(n267), .Y(n268) );
  NOR3XL U488 ( .A(n284), .B(n477), .C(n268), .Y(n474) );
  OAI22XL U489 ( .A0(b_var[4]), .A1(n462), .B0(n269), .B1(n461), .Y(n271) );
  OAI22XL U490 ( .A0(b_var[3]), .A1(n462), .B0(n272), .B1(n461), .Y(n274) );
  OAI22XL U491 ( .A0(b_var[0]), .A1(n462), .B0(n277), .B1(n461), .Y(n276) );
  OAI21XL U492 ( .A0(b_var[1]), .A1(n360), .B0(n278), .Y(n279) );
  NOR2XL U493 ( .A(n493), .B(n279), .Y(n280) );
  OAI22XL U494 ( .A0(b_var[2]), .A1(var_code[0]), .B0(n281), .B1(
        var_code[1]), .Y(n283) );
  NOR2XL U495 ( .A(n469), .B(n468), .Y(n467) );
  NOR2XL U496 ( .A(n472), .B(n471), .Y(n470) );
  NOR2XL U497 ( .A(n474), .B(n475), .Y(n484) );
  NAND3XL U498 ( .A(b_var[5]), .B(anl), .C(n473), .Y(n481) );
  OAI21XL U499 ( .A0(n288), .A1(n493), .B0(n486), .Y(n289) );
  OAI21XL U500 ( .A0(n486), .A1(cout7), .B0(n289), .Y(n489) );
  NOR2XL U501 ( .A(n489), .B(n488), .Y(n487) );
  OAI21XL U502 ( .A0(n296), .A1(n293), .B0(n297), .Y(result[11]) );
  NAND3XL U503 ( .A(b_var[12]), .B(anl), .C(n300), .Y(n311) );
  OAI21XL U504 ( .A0(n300), .A1(n307), .B0(n311), .Y(n301) );
  MXI2XL U505 ( .A(n312), .B(n302), .S0(n301), .Y(result[13]) );
  NOR2XL U506 ( .A(n493), .B(n304), .Y(n305) );
  NOR3XL U507 ( .A(n306), .B(n305), .C(n312), .Y(n308) );
  NAND3XL U508 ( .A(n312), .B(anl), .C(b_var[13]), .Y(n310) );
  OAI21XL U509 ( .A0(n312), .A1(n311), .B0(n310), .Y(n320) );
  NOR2XL U510 ( .A(n321), .B(n320), .Y(n316) );
  OAI21XL U511 ( .A0(n316), .A1(n322), .B0(n315), .Y(result[14]) );
  OAI21XL U512 ( .A0(n493), .A1(n317), .B0(n319), .Y(n318) );
  NOR2XL U513 ( .A(n326), .B(n323), .Y(n335) );
  NAND3XL U514 ( .A(n326), .B(b_var[15]), .C(anl), .Y(n324) );
  OAI22XL U515 ( .A0(b_var[16]), .A1(n462), .B0(n331), .B1(n461), .Y(n328) );
  OAI22XL U516 ( .A0(b_var[17]), .A1(n462), .B0(n337), .B1(n461), .Y(n330) );
  OAI21XL U517 ( .A0(n331), .A1(n493), .B0(n333), .Y(n334) );
  OAI21XL U518 ( .A0(n333), .A1(n332), .B0(n334), .Y(n349) );
  NAND3XL U519 ( .A(n336), .B(n349), .C(n350), .Y(n339) );
  OAI21XL U520 ( .A0(n337), .A1(n493), .B0(n351), .Y(n338) );
  OAI22XL U521 ( .A0(b_var[18]), .A1(var_code[0]), .B0(n340), .B1(
        var_code[1]), .Y(n342) );
  OAI22XL U522 ( .A0(b_var[19]), .A1(var_code[0]), .B0(n365), .B1(
        var_code[1]), .Y(n347) );
  OAI22XL U523 ( .A0(b_var[19]), .A1(var_code[2]), .B0(n365), .B1(
        var_code[3]), .Y(n345) );
  NAND3XL U524 ( .A(n351), .B(anl), .C(b_var[17]), .Y(n348) );
  OAI21XL U525 ( .A0(n351), .A1(n349), .B0(n348), .Y(n353) );
  NOR2XL U526 ( .A(n351), .B(n350), .Y(n352) );
  OAI21XL U527 ( .A0(n353), .A1(n352), .B0(n356), .Y(n354) );
  OAI21XL U528 ( .A0(n356), .A1(n355), .B0(n354), .Y(n357) );
  OAI21XL U529 ( .A0(n366), .A1(n357), .B0(n364), .Y(n358) );
  OAI22XL U530 ( .A0(b_var[20]), .A1(var_code[0]), .B0(n373), .B1(
        var_code[1]), .Y(n363) );
  OAI22XL U531 ( .A0(b_var[20]), .A1(var_code[2]), .B0(n373), .B1(
        var_code[3]), .Y(n361) );
  OAI21XL U532 ( .A0(n374), .A1(n367), .B0(n372), .Y(n368) );
  OAI22XL U533 ( .A0(b_var[21]), .A1(var_code[0]), .B0(n378), .B1(
        var_code[1]), .Y(n371) );
  OAI22XL U534 ( .A0(b_var[21]), .A1(var_code[2]), .B0(n378), .B1(
        var_code[3]), .Y(n369) );
  OAI22XL U535 ( .A0(n384), .A1(n400), .B0(n379), .B1(n409), .Y(result[21]) );
  MXI2XL U536 ( .A(n382), .B(n383), .S0(n380), .Y(result[22]) );
  NAND3XL U537 ( .A(anl), .B(b_var[22]), .C(n383), .Y(n395) );
  OAI21XL U538 ( .A0(n384), .A1(n394), .B0(n395), .Y(n398) );
  OAI22XL U539 ( .A0(b_var[23]), .A1(n462), .B0(n393), .B1(n461), .Y(n387) );
  OAI22XL U540 ( .A0(b_var[23]), .A1(n464), .B0(n393), .B1(n463), .Y(n385) );
  OAI21XL U541 ( .A0(n493), .A1(n393), .B0(n399), .Y(n397) );
  OAI21XL U542 ( .A0(n399), .A1(n398), .B0(n397), .Y(n405) );
  NAND3XL U543 ( .A(n406), .B(b_var[24]), .C(anl), .Y(n404) );
  OAI21XL U544 ( .A0(n406), .A1(n403), .B0(n404), .Y(n410) );
  OAI21XL U545 ( .A0(n406), .A1(n405), .B0(n404), .Y(n413) );
  MXI2XL U546 ( .A(n408), .B(n414), .S0(n407), .Y(result[25]) );
  OAI21XL U547 ( .A0(n493), .A1(n411), .B0(n414), .Y(n412) );
  OAI21XL U548 ( .A0(n414), .A1(n413), .B0(n412), .Y(n422) );
  OAI21XL U549 ( .A0(n416), .A1(n423), .B0(n415), .Y(result[26]) );
  NOR2XL U550 ( .A(n423), .B(n417), .Y(n431) );
  OAI22XL U551 ( .A0(b_var[27]), .A1(n462), .B0(n427), .B1(n461), .Y(n420) );
  OAI22XL U552 ( .A0(b_var[27]), .A1(n464), .B0(n427), .B1(n463), .Y(n418) );
  NAND3XL U553 ( .A(n423), .B(b_var[26]), .C(anl), .Y(n421) );
  OAI21XL U554 ( .A0(n431), .A1(n428), .B0(n429), .Y(n424) );
  OAI22XL U555 ( .A0(b_var[28]), .A1(n462), .B0(n433), .B1(n461), .Y(n426) );
  OAI21XL U556 ( .A0(n493), .A1(n427), .B0(n429), .Y(n430) );
  OAI21XL U557 ( .A0(n429), .A1(n428), .B0(n430), .Y(n448) );
  NAND3XL U558 ( .A(n432), .B(n448), .C(n449), .Y(n435) );
  OAI21XL U559 ( .A0(n433), .A1(n493), .B0(n450), .Y(n434) );
  OAI22XL U560 ( .A0(b_var[29]), .A1(var_code[0]), .B0(n436), .B1(
        var_code[1]), .Y(n438) );
  OAI22XL U561 ( .A0(b_var[30]), .A1(var_code[0]), .B0(n459), .B1(
        var_code[1]), .Y(n446) );
  OAI22XL U562 ( .A0(b_var[30]), .A1(var_code[2]), .B0(n459), .B1(
        var_code[3]), .Y(n444) );
  NAND3XL U563 ( .A(n450), .B(anl), .C(b_var[28]), .Y(n447) );
  OAI21XL U564 ( .A0(n450), .A1(n448), .B0(n447), .Y(n452) );
  NOR2XL U565 ( .A(n450), .B(n449), .Y(n451) );
  OAI21XL U566 ( .A0(n452), .A1(n451), .B0(n455), .Y(n453) );
  OAI21XL U567 ( .A0(n460), .A1(n456), .B0(n458), .Y(n457) );
  OAI22XL U568 ( .A0(b_var[31]), .A1(n462), .B0(n492), .B1(n461), .Y(n466) );
  MXI2XL U569 ( .A(n491), .B(cout30), .S0(n494), .Y(result[31]) );
  OAI22XL U570 ( .A0(n477), .A1(n475), .B0(n473), .B1(n476), .Y(result[5])
         );
endmodule

