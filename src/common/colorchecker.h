/*
    This file is part of darktable,
    Copyright (C) 2020 darktable developers.

    darktable is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    darktable is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with darktable.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * These are the CIELab values of Color Checker reference targets
 */

// types of targets we support
typedef enum dt_color_checker_targets
{
  COLOR_CHECKER_PASSPORT_XRITE_24 = 0,
  COLOR_CHECKER_XRITE_24 = 1,
  COLOR_CHECKER_SPYDER_48 = 2,
  COLOR_CHECKER_LAST
} dt_color_checker_targets;

// helper to deal with patch color
typedef struct dt_color_checker_patch
{
  const char *name;     // mnemonic name for the patch
  float Lab[3];         // reference color in CIE Lab

  // (x, y) position of the patch center, relatively to the guides (white dots)
  // in ratio of the grid dimension along that axis
  struct {
    float x;
    float y;
  };
} dt_color_checker_patch;

typedef struct dt_color_checker_t
{
  const char *name;
  const char *author;
  const char *date;
  const char *manufacturer;
  dt_color_checker_targets type;

  float ratio;                        // format ratio of the chart, guide to guide (white dots)
  float radius;                       // radius of a patch in ratio of the checker diagonal
  size_t patches;                     // number of patches in target
  size_t size[2];                     // dimension along x, y axes
  size_t middle_grey;                 // index of the closest patch to 20% neutral grey
  size_t white;                       // index of the closest patch to pure white
  size_t black;                       // index of the closest patch to pure black
  dt_color_checker_patch values[];    // array of colors
} dt_color_checker_t;


dt_color_checker_t xrite_24 = { .name = "Xrite ColorChecker 24",
                                .author = "Graeme Gill, ArgyllCMS from Gretag Macbeth reference",
                                .date = "Feb 18, 2008",
                                .manufacturer = "X-Rite/Gretag Macbeth",
                                .type = COLOR_CHECKER_XRITE_24,
                                .radius = 0.055f,
                                .ratio = 2.f / 3.f,
                                .patches = 24,
                                .size = { 4, 6 },
                                .middle_grey = 19,
                                .white = 18,
                                .black = 23,
                                .values = { { "A1", { 37.99,   13.56,   14.06 }, { 0.087, 0.125}},
                                            { "A2", { 65.71,   18.13,   17.81 }, { 0.250, 0.125}},
                                            { "A3", { 49.93,   -4.88,  -21.93 }, { 0.417, 0.125}},
                                            { "A4", { 43.14,  -13.10,   21.91 }, { 0.584, 0.125}},
                                            { "A5", { 55.11,    8.84,  -25.40 }, { 0.751, 0.125}},
                                            { "A6", { 70.72,  -33.40,   -0.20 }, { 0.918, 0.125}},
                                            { "B1", { 62.66,   36.07,   57.10 }, { 0.087, 0.375}},
                                            { "B2", { 40.02,   10.41,  -45.96 }, { 0.250, 0.375}},
                                            { "B3", { 51.12,   48.24,   16.25 }, { 0.417, 0.375}},
                                            { "B4", { 30.33,   22.98,  -21.59 }, { 0.584, 0.375}},
                                            { "B5", { 72.53,  -23.71,   57.26 }, { 0.751, 0.375}},
                                            { "B6", { 71.94,   19.36,   67.86 }, { 0.918, 0.375}},
                                            { "C1", { 28.78,   14.18,  -50.30 }, { 0.087, 0.625}},
                                            { "C2", { 55.26,  -38.34,   31.37 }, { 0.250, 0.625}},
                                            { "C3", { 42.10,   53.38,   28.19 }, { 0.417, 0.625}},
                                            { "C4", { 81.73,    4.04,   79.82 }, { 0.584, 0.625}},
                                            { "C5", { 51.94,   49.99,  -14.57 }, { 0.751, 0.625}},
                                            { "C6", { 51.04,  -28.63,  -28.64 }, { 0.918, 0.625}},
                                            { "D1", { 96.54,   -0.43,    1.19 }, { 0.087, 0.875}},
                                            { "D2", { 81.26,   -0.64,   -0.34 }, { 0.250, 0.875}},
                                            { "D3", { 66.77,   -0.73,   -0.50 }, { 0.417, 0.875}},
                                            { "D4", { 50.87,   -0.15,   -0.27 }, { 0.584, 0.875}},
                                            { "D5", { 35.66,   -0.42,   -1.23 }, { 0.751, 0.875}},
                                            { "D6", { 20.46,   -0.08,   -0.97 }, { 0.918, 0.875}} } };

dt_color_checker_t spyder_48 = {  .name = "Datacolor SpyderCheckr 48",
                                  .author = "Aurélien PIERRE",
                                  .date = "dec, 9 2016",
                                  .manufacturer = "DataColor",
                                  .type = COLOR_CHECKER_SPYDER_48,
                                  .ratio = 2.f / 3.f,
                                  .radius = 0.035,
                                  .patches = 48,
                                  .size = { 8, 6 },
                                  .middle_grey = 25,
                                  .white = 24,
                                  .black = 29,
                                  .values = { { "A1", { 61.35,  34.81,  18.38 }, { 0.071, 0.104 } },
                                              { "A2", { 75.50 ,  5.84,  50.42 }, { 0.071, 0.257 } },
                                              { "A3", { 66.82,	-25.1,	23.47 }, { 0.071, 0.411 } },
                                              { "A4", { 60.53,	-22.6, -20.40 }, { 0.071, 0.589 } },
                                              { "A5", { 59.66,	-2.03, -28.46 }, { 0.071, 0.743 } },
                                              { "A6", { 59.15,	30.83,  -5.72 }, { 0.071, 0.896 } },
                                              { "B1", { 82.68,	 5.03,	 3.02 }, { 0.175, 0.104 } },
                                              { "B2", { 82.25,	-2.42,	 3.78 }, { 0.175, 0.257 } },
                                              { "B3", { 82.29,	 2.20,	-2.04 }, { 0.175, 0.411 } },
                                              { "B4", { 24.89,	 4.43,	 0.78 }, { 0.175, 0.589 } },
                                              { "B5", { 25.16,	-3.88,	 2.13 }, { 0.175, 0.743 } },
                                              { "B6", { 26.13,	 2.61,	-5.03 }, { 0.175, 0.896 } },
                                              { "C1", { 85.42,	 9.41,	14.49 }, { 0.279, 0.104 } },
                                              { "C2", { 74.28,	 9.05,	27.21 }, { 0.279, 0.257 } },
                                              { "C3", { 64.57,	12.39,	37.24 }, { 0.279, 0.411 } },
                                              { "C4", { 44.49,	17.23,	26.24 }, { 0.279, 0.589 } },
                                              { "C5", { 25.29,	 7.95,	 8.87 }, { 0.279, 0.743 } },
                                              { "C6", { 22.67,	 2.11,	-1.10 }, { 0.279, 0.896 } },
                                              { "D1", { 92.72,	 1.89,	 2.76 }, { 0.384, 0.104 } },
                                              { "D2", { 88.85,	 1.59,	 2.27 }, { 0.384, 0.257 } },
                                              { "D3", { 73.42,	 0.99,	 1.89 }, { 0.384, 0.411 } },
                                              { "D4", { 57.15,	 0.57,	 1.19 }, { 0.384, 0.589 } },
                                              { "D5", { 41.57,	 0.24,	 1.45 }, { 0.384, 0.743 } },
                                              { "D6", { 25.65,	 1.24,	 0.05 }, { 0.384, 0.896 } },
                                              { "E1", { 96.04,	 2.16,	 2.60 }, { 0.616, 0.104 } },
                                              { "E2", { 80.44,	 1.17,	 2.05 }, { 0.616, 0.257 } },
                                              { "E3", { 65.52,	 0.69,	 1.86 }, { 0.616, 0.411 } },
                                              { "E4", { 49.62,	 0.58,	 1.56 }, { 0.616, 0.589 } },
                                              { "E5", { 33.55,	 0.35,	 1.40 }, { 0.616, 0.743 } },
                                              { "E6", { 16.91,	 1.43,	-0.81 }, { 0.616, 0.896 } },
                                              { "F1", { 47.12, -32.50, -28.75 }, { 0.721, 0.104 } },
                                              { "F2", { 50.49,	53.45, -13.55 }, { 0.721, 0.257 } },
                                              { "F3", { 83.61,	 3.36,	87.02 }, { 0.721, 0.411 } },
                                              { "F4", { 41.05,	60.75,	31.17 }, { 0.721, 0.589 } },
                                              { "F5", { 54.14, -40.80,	34.75 }, { 0.721, 0.743 } },
                                              { "F6", { 24.75,	13.78, -49.48 }, { 0.721, 0.896 } },
                                              { "G1", { 60.94,	38.21,	61.31 }, { 0.825, 0.104 } },
                                              { "G2", { 37.80,	 7.30, -43.04 }, { 0.825, 0.257 } },
                                              { "G3", { 49.81,	48.50,	15.76 }, { 0.825, 0.411 } },
                                              { "G4", { 28.88,	19.36, -24.48 }, { 0.825, 0.589 } },
                                              { "G5", { 72.45, -23.60,	60.47 }, { 0.825, 0.743 } },
                                              { "G6", { 71.65,	23.74,	72.28 }, { 0.825, 0.896 } },
                                              { "H1", { 70.19, -31.90,	 1.98 }, { 0.929, 0.104 } },
                                              { "H2", { 54.38,	 8.84, -25.71 }, { 0.929, 0.257 } },
                                              { "H3", { 42.03, -15.80,	22.93 }, { 0.929, 0.411 } },
                                              { "H4", { 48.82,	-5.11, -23.08 }, { 0.929, 0.589 } },
                                              { "H5", { 65.10,	18.14,	16.68 }, { 0.929, 0.743 } },
                                              { "H6", { 36.13,	14.15,	15.78 }, { 0.929, 0.896 } } } };


dt_color_checker_t xrite_PP24 = { .name = "Xrite ColorChecker Passport 24",
                                  .author = "Ben Goren <ben@trumpetpower.com>",
                                  .date = "Fri Aug  3 15:35:05 MST 2012",
                                  .manufacturer = "X-Rite/Gretag Macbeth",
                                  .type = COLOR_CHECKER_PASSPORT_XRITE_24,
                                  .radius = 0.055f,
                                  .ratio = 2.f / 3.f,
                                  .patches = 24,
                                  .size = { 4, 6 },
                                  .middle_grey = 19,
                                  .white = 18,
                                  .black = 23,
                                  .values = {
                                              { "A1", { 37.972545,  12.84975,  13.905933  }, { 0.087, 0.125 } },
                                              { "A2", { 65.021429,  17.736538, 18.105244  }, { 0.250, 0.125 } },
                                              { "A3", { 49.767263,  -4.838656, -21.688821 }, { 0.417, 0.125 } },
                                              { "A4", { 43.171313, -11.673243,  22.59988  }, { 0.584, 0.125 } },
                                              { "A5", { 55.095608,   8.054,    -23.674108 }, { 0.751, 0.125 } },
                                              { "A6", { 70.345563, -33.87973,    0.591375 }, { 0.918, 0.125 } },
                                              { "B1", { 62.491292,  36.974257,  57.538878 }, { 0.087, 0.375 } },
                                              { "B2", { 40.66193,   10.745627, -43.972357 }, { 0.250, 0.375 } },
                                              { "B3", { 51.418556,  47.83579,   16.229131 }, { 0.417, 0.375 } },
                                              { "B4", { 31.232269,  21.992198, -20.376399 }, { 0.584, 0.375 } },
                                              { "B5", { 72.291888, -22.389553,  57.145982 }, { 0.751, 0.375 } },
                                              { "B6", { 71.992078,  20.037754,  67.243006 }, { 0.918, 0.375 } },
                                              { "C1", { 28.900464,  11.613838, -47.531575 }, { 0.087, 0.625 } },
                                              { "C2", { 55.786947, -38.099805,  32.761011 }, { 0.250, 0.625 } },
                                              { "C3", { 42.323678,  50.646029,  27.808803 }, { 0.417, 0.625 } },
                                              { "C4", { 81.403423,   3.722966,  80.589317 }, { 0.584, 0.625 } },
                                              { "C5", { 52.352077,  49.539466, -13.465303 }, { 0.751, 0.625 } },
                                              { "C6", { 50.742046, -29.398805, -26.412062 }, { 0.918, 0.625 } },
                                              { "D1", { 96.260066,  -0.692605,   4.206323 }, { 0.087, 0.875 } },
                                              { "D2", { 81.762472,  -0.207864,   0.973581 }, { 0.250, 0.875 } },
                                              { "D3", { 67.22286,   -0.574879,   0.364223 }, { 0.417, 0.875 } },
                                              { "D4", { 51.058515 , -0.355289,   0.481164 }, { 0.584, 0.875 } },
                                              { "D5", { 36.300462,  -0.566396,  -0.30356  }, { 0.751, 0.875 } },
                                              { "D6", { 21.283684,   0.258119,   0.046995 }, { 0.918, 0.875 } } } };



dt_color_checker_t * dt_get_color_checker(const dt_color_checker_targets target_type)
{
  switch(target_type)
  {
    case COLOR_CHECKER_PASSPORT_XRITE_24:
      return &xrite_PP24;

    case COLOR_CHECKER_XRITE_24:
      return &xrite_24;

    case COLOR_CHECKER_SPYDER_48:
      return &spyder_48;

    case COLOR_CHECKER_LAST:
      return &xrite_24;
  }

  return &xrite_24;
}

/**
 * helper functions
 */

// get a patch index in the list of values from the coordinates of the patch in the checker array
static inline size_t dt_color_checker_get_index(const dt_color_checker_t *const target_checker, const size_t coordinates[2])
{
  // patches are stored column-major
  const size_t height = target_checker->size[1];
  return CLAMP(height * coordinates[0] + coordinates[1], 0, target_checker->patches - 1);
}

// get a a patch coordinates of in the checker array from the patch index in the list of values
static inline void dt_color_checker_get_coordinates(const dt_color_checker_t *const target_checker, size_t *coordinates, const size_t index)
{
  // patches are stored column-major
  const size_t idx = CLAMP(index, 0, target_checker->patches - 1);
  const size_t height = target_checker->size[1];
  const size_t num_col = idx / height;
  const size_t num_lin = idx - num_col * height;
  coordinates[0] = CLAMP(num_col, 0, target_checker->size[0] - 1);
  coordinates[1] = CLAMP(num_lin, 0, target_checker->size[1] - 1);
}

// find a patch matching a name
static inline const dt_color_checker_patch *const dt_color_checker_get_patch_by_name(const dt_color_checker_t *const target_checker,
                                                                              const char *name, size_t *index)
{
  size_t idx = -1;
  const dt_color_checker_patch *patch = NULL;

  for(size_t k = 0; k < target_checker->patches; k++)
    if(strcmp(name, target_checker->values[k].name) == 0)
    {
      idx = k;
      patch = &target_checker->values[k];
      break;
    }

  if(patch == NULL) fprintf(stderr, "No patch matching name `%s` was found in %s\n", name, target_checker->name);

  if(index ) *index = idx;
  return patch;
}
