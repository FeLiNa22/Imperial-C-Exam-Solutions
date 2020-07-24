#ifndef TEST_REGIONS_H
#define TEST_REGIONS_H

// Array of sorted dummy regions for testing purposes.
static const region_t test_regions[] = {
  { .position = { .x = 0,   .y = 0 },
    .extent = {.width = 549, .height = 525}, .depth = 0 },
  { .position = { .x = 150,   .y = 104 },
    .extent = {.width = 272, .height = 249}, .depth = 1 },
  { .position = { .x = 182,   .y = 163 },
    .extent = {.width = 38, .height = 62}, .depth = 2 },
  { .position = { .x = 310,   .y = 170 },
    .extent = {.width = 78, .height = 68}, .depth = 2 },
  { .position = { .x = 199,   .y = 272 },
    .extent = {.width = 186, .height = 42}, .depth = 2 },
  { .position = { .x = 31,   .y = 360 },
    .extent = {.width = 60, .height = 126}, .depth = 1 },
  { .position = { .x = 364,   .y = 427 },
    .extent = {.width = 133, .height = 70}, .depth = 1 }
};


// The number of test regions defined.
static const int num_test_regions = sizeof(test_regions) / sizeof (test_regions[0]);

#endif
