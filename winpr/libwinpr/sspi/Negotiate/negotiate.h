/**
 * WinPR: Windows Portable Runtime
 * Negotiate Security Package
 *
 * Copyright 2011-2012 Jiten Pathy
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef WINPR_SSPI_NEGOTIATE_PRIVATE_H
#define WINPR_SSPI_NEGOTIATE_PRIVATE_H

#include <winpr/sspi.h>

#include "../sspi.h"

#define NTLM_OID "1.3.6.1.4.1.311.2.2.10"

typedef enum
{
	NEGOTIATE_STATE_INITIAL,
	NEGOTIATE_STATE_NEGORESP,
	NEGOTIATE_STATE_MIC,
	NEGOTIATE_STATE_FINAL
} NEGOTIATE_STATE;

typedef struct Mech_st Mech;

typedef struct
{
	NEGOTIATE_STATE state;
	CtxtHandle sub_context;
	SecBuffer mechTypes;
	const Mech *mech;
	BOOL mic;
	BOOL spnego;
} NEGOTIATE_CONTEXT;

extern const SecPkgInfoA NEGOTIATE_SecPkgInfoA;
extern const SecPkgInfoW NEGOTIATE_SecPkgInfoW;
extern const SecurityFunctionTableA NEGOTIATE_SecurityFunctionTableA;
extern const SecurityFunctionTableW NEGOTIATE_SecurityFunctionTableW;

#endif /* WINPR_SSPI_NEGOTIATE_PRIVATE_H */
