//==============================================================================
//
//  OvenMediaEngine
//
//  Created by Jaejong Bong
//  Copyright (c) 2019 AirenSoft. All rights reserved.
//
//==============================================================================

#pragma once

#include "segment_stream/segment_stream_interceptor.h"

class CmafInterceptor : public SegmentStreamInterceptor
{
public:
    CmafInterceptor();
	~CmafInterceptor();

protected:
    //--------------------------------------------------------------------
	// Implementation of HttpRequestInterceptorInterface
	//--------------------------------------------------------------------
	bool IsInterceptorForRequest(const std::shared_ptr<const HttpRequest> &request, const std::shared_ptr<const HttpResponse> &response) override;
};
