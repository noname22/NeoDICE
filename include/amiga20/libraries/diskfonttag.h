/*
**	$Filename: libraries/diskfonttag.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 37.18 $
**	$Date: 91/11/08 $
**
**	libraries/diskfonttag.h -- tag definitions for .otag files
**
**	(C) Copyright 1990-1991 Commodore-Amiga, Inc.
**	    All Rights Reserved
*/

/* Level 0 entries never appear in the .otag tag list, but appear in font
 * specifications */
#define  OT_Level0	TAG_USER
/* Level 1 entries are required to exist in the .otag tag list */
#define  OT_Level1	(TAG_USER | 0x1000)
/* Level 2 entries are optional typeface metric tags */
#define  OT_Level2	(TAG_USER | 0x2000)
/* Level 3 entries are required for some OT_Engines */
#define  OT_Level3	(TAG_USER | 0x3000)
/* Indirect entries are at (tag address + data offset) */
#define  OT_Indirect	0x8000

/********************************************************************/
/* font specification tags */

/* OT_DeviceDPI specifies the target device dots per inch -- X DPI is
 * in the high word, Y DPI in the low word. */
#define  OT_DeviceDPI	(OT_Level0 | 0x01)	/* == TA_DeviceDPI */

/* OT_DotSize specifies the target device dot size as a percent of
 * it's resolution-implied size -- X percent in high word, Y percent
 * in low word. */
#define  OT_DotSize	(OT_Level0 | 0x02)

/* OT_PointHeight specifies the requested point height of a typeface,
 * specifically, the height and nominal width of the em-square.
 * The point referred to here is 1/72".  It is encoded as a fixed
 * binary number. */
#define  OT_PointHeight	(OT_Level0 | 0x08)

/* OT_PointSize specifies the requested point height of a typeface
 * The point referred to here is 1/72".  It is encoded here as
 * (points * 16) */
#define  OT_PointSize	(OT_Level0 | 0x10)

/********************************************************************/
/* .otag tags */

/* suffix for files in FONTS: that contain these tags */
#define  OTSUFFIX	".otag"

/* OT_FileIdent both identifies this file and verifies its size.
 * It is required to be the first tag in the file. */
#define  OT_FileIdent	(OT_Level1 | 0x01)

/* OT_Engine specifies the font engine this file is designed to use */
#define  OT_Engine	(OT_Level1 | OT_Indirect | 0x02)
#define  OTE_Bullet	"bullet"

/* OT_Family is the family name of this typeface */
#define  OT_Family	(OT_Level1 | OT_Indirect | 0x03)

/* The name of this typeface is implicit in the name of the .otag file */
/* OT_BName is used to find the bold variant of this typeface */
#define	 OT_BName	(OT_Level2 | OT_Indirect | 0x05)
/* OT_IName is used to find the italic variant of this typeface */
#define	 OT_IName	(OT_Level2 | OT_Indirect | 0x06)
/* OT_BIName is used to find the bold italic variant of this typeface */
#define	 OT_BIName	(OT_Level2 | OT_Indirect | 0x07)

/* OT_SymSet is used to select the symbol set that has the OT_YSizeFactor
 * described here.  Other symbol sets might have different extremes */
#define  OT_SymbolSet	(OT_Level1 | 0x10)

/* OT_YSizeFactor is a ratio to assist in calculating the Point height
 * to BlackHeight relationship -- high word: Point height term, low
 * word: Black height term -- pointSize = ysize*<high>/<low> */
#define  OT_YSizeFactor	(OT_Level1 | 0x11)

/* OT_SpaceWidth specifies the width of the space character relative
 * to the character height */
#define  OT_SpaceWidth	(OT_Level2 | 0x12)

/* OT_IsFixed is a boolean indicating that all the characters in the
 * typeface are intended to have the same character advance */
#define  OT_IsFixed	(OT_Level2 | 0x13)

/* OT_SerifFlag is a boolean indicating if the character has serifs */
#define  OT_SerifFlag	(OT_Level1 | 0x14)

/* OT_StemWeight is an unsigned byte indicating the weight of the character */
#define  OT_StemWeight	(OT_Level1 | 0x15)

#define  OTS_UltraThin	  8	/*   0- 15 */
#define  OTS_ExtraThin	 24	/*  16- 31 */
#define  OTS_Thin	 40	/*  32- 47 */
#define  OTS_ExtraLight	 56	/*  48- 63 */
#define  OTS_Light	 72	/*  64- 79 */
#define  OTS_DemiLight	 88	/*  80- 95 */
#define  OTS_SemiLight	104	/*  96-111 */
#define  OTS_Book	120	/* 112-127 */
#define  OTS_Medium	136	/* 128-143 */
#define  OTS_SemiBold	152	/* 144-159 */
#define  OTS_DemiBold	168	/* 160-175 */
#define  OTS_Bold	184	/* 176-191 */
#define  OTS_ExtraBold	200	/* 192-207 */
#define  OTS_Black	216	/* 208-223 */
#define  OTS_ExtraBlack	232	/* 224-239 */
#define  OTS_UltraBlack	248	/* 240-255 */

/* OT_SlantStyle is an unsigned byte indicating the font posture */
#define  OT_SlantStyle	(OT_Level1 | 0x16)
#define  OTS_Upright	0
#define  OTS_Italic	1	/* Oblique, Slanted, etc. */
#define  OTS_LeftItalic	2	/* Reverse Slant */

/* OT_HorizStyle is an unsigned byte indicating the appearance width */
#define  OT_HorizStyle	(OT_Level1 | 0x17)
#define  OTH_UltraCompressed	 16	/*   0- 31 */
#define  OTH_ExtraCompressed	 48	/*  32- 63 */
#define  OTH_Compressed		 80	/*  64- 95 */
#define  OTH_Condensed		112	/*  96-127 */
#define  OTH_Normal		144	/* 128-159 */
#define  OTH_SemiExpanded	176	/* 160-191 */
#define  OTH_Expanded		208	/* 192-223 */
#define  OTH_ExtraExpanded	240	/* 224-255 */

/* OT_SpaceFactor specifies the width of the space character relative
 * to the character height */
#define  OT_SpaceFactor	(OT_Level2 | 0x18)

/* OT_InhibitAlgoStyle indicates which ta_Style bits, if any, should
 * be ignored even if the font does not already have that quality.
 * For example, if FSF_BOLD is set and the typeface is not bold but
 * the user specifies bold, the application or diskfont library is
 * not to artificially embolden the normal character to achieve a
 * bold result. */
#define  OT_InhibitAlgoStyle (OT_Level2 | 0x19)

/* OT_AvailSizes is an indirect pointer to sorted UWORDs, 0th is count */
#define	 OT_AvailSizes	(OT_Level1 | OT_Indirect | 0x20)
#define  OT_MAXAVAILSIZES	20	/* no more than 20 sizes allowed */

/* OT_SpecCount is the count number of parameters specified here */
#define  OT_SpecCount	(OT_Level1 | 0x100)

/* Specs can be created as appropriate for the engine by ORing in the
 * parameter number (1 is first, 2 is second, ... up to 15th) */
#define	 OT_Spec	(OT_Level1 | 0x100)
/* OT_Spec1 is the (first) parameter to the font engine to select
 * this particular typeface */
#define	 OT_Spec1	(OT_Level1 | 0x101)
