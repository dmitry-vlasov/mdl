/*****************************************************************************/
/* Project name:    smm - verifier for the Simplified MetaMath language      */
/* File name:       smm_types_storage.hpp                                    */
/* Description:     container storage policies                               */
/* Copyright:       (c) 2006-2010 Dmitri Vlasov                              */
/* Author:          Dmitri Yurievich Vlasov, Novosibirsk, Russia             */
/* Email:           vlasov at academ.org                                     */
/* URL:             http://mathdevlanguage.sourceforge.net                   */
/* Modified by:                                                              */
/* License:         GNU General Public License Version 3                     */
/*****************************************************************************/

#pragma once

namespace smm {
namespace storage {

	using nstd :: container :: storage :: ByValue;
	using nstd :: container :: storage :: ByPointer;
	using nstd :: container :: storage :: ByInheritance;
}
}


