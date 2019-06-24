﻿//==============================================================================
//
//  OvenMediaEngine
//
//  Created by Jaejong Bong
//  Copyright (c) 2018 AirenSoft. All rights reserved.
//
//==============================================================================

#pragma once

#include <vector>
#include <deque>
#include <string>
#include <memory>
#include <base/common_types.h>
#include <base/ovlibrary/byte_io.h>

enum class M4sMediaType
{
	Video,
	Audio,
	Data,
};

//====================================================================================================
// Fragment Sample Data
//====================================================================================================
struct FragmentSampleData
{
public:
    FragmentSampleData(uint64_t duration_,
                       uint32_t flag_,
                       uint64_t timestamp_,
                       uint32_t composition_time_offset_,
                       std::shared_ptr<ov::Data> &data_)
    {
        duration                =  duration_;
        flag                    = flag_;
        timestamp               = timestamp_;
        composition_time_offset = composition_time_offset_;
        data		            = data_;
    }

public:
    uint64_t duration;
    uint32_t flag;
    uint64_t timestamp;
    uint32_t composition_time_offset;
    std::shared_ptr<ov::Data> data;
};

//====================================================================================================
// M4sWriter
//====================================================================================================
class M4sWriter
{
public:
	M4sWriter(M4sMediaType media_type);
	virtual ~M4sWriter() = default;

protected :
	bool WriteText(std::string text, std::shared_ptr<std::vector<uint8_t>> &data_stream);
	bool WriteData(const std::vector<uint8_t> &data,  std::shared_ptr<std::vector<uint8_t>> &data_stream);
    bool WriteData(const std::shared_ptr<ov::Data> &data,  std::shared_ptr<std::vector<uint8_t>> &data_stream);
	bool WriteData(const uint8_t *data,  int data_size, std::shared_ptr<std::vector<uint8_t>> &data_stream);
	bool WriteInit(uint8_t value, int init_size, std::shared_ptr<std::vector<uint8_t>> &data_stream);
	bool WriteUint64(uint64_t value, std::shared_ptr<std::vector<uint8_t>> &data_stream);
	bool WriteUint32(uint32_t value, std::shared_ptr<std::vector<uint8_t>> &data_stream);
	bool WriteUint24(uint32_t value, std::shared_ptr<std::vector<uint8_t>> &data_stream);
	bool WriteUint16(uint16_t value, std::shared_ptr<std::vector<uint8_t>> &data_stream);
	bool WriteUint8(uint8_t value, std::shared_ptr<std::vector<uint8_t>> &data_stream);

	int BoxDataWrite(std::string type, std::shared_ptr<std::vector<uint8_t>> &data, std::shared_ptr<std::vector<uint8_t>> &data_stream);
	int BoxDataWrite(std::string type, uint8_t version, uint32_t flags, std::shared_ptr<std::vector<uint8_t>> &data, std::shared_ptr<std::vector<uint8_t>> &data_stream);

protected :
	M4sMediaType _media_type;
};