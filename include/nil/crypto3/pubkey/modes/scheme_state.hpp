//---------------------------------------------------------------------------//
// Copyright (c) 2018-2020 Mikhail Komarov <nemo@nil.foundation>
//
// MIT License
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//---------------------------------------------------------------------------//

#ifndef CRYPTO3_PUBKEY_THRESHOLD_SCHEME_STATE_HPP
#define CRYPTO3_PUBKEY_THRESHOLD_SCHEME_STATE_HPP

#include <boost/accumulators/framework/accumulator_set.hpp>
#include <boost/accumulators/framework/features.hpp>

#include <nil/crypto3/pubkey/scheme_state.hpp>

// #include <nil/crypto3/pubkey/accumulators/scheme.hpp>
// #include <nil/crypto3/pubkey/modes/accumulators/keys.hpp>
// #include <nil/crypto3/pubkey/modes/accumulators/signatures.hpp>
#include <nil/crypto3/pubkey/modes/accumulators/sign.hpp>
#include <nil/crypto3/pubkey/modes/accumulators/part_verify.hpp>

namespace nil {
    namespace crypto3 {
        namespace pubkey {
            /*!
             * @brief Accumulator set with pre-defined block cipher accumulator params.
             *
             * Meets the requirements of AccumulatorSet
             *
             * @ingroup block
             *
             * @tparam Mode Cipher state preprocessing mode type (e.g. isomorphic_encryption_mode<aes128>)
             * @tparam Endian
             * @tparam ValueBits
             * @tparam LengthBits
             */
            // template<typename ProcessingMode>
            // using keys_accumulator_set = boost::accumulators::accumulator_set<
            //     digest<ProcessingMode::input_block_bits>,
            //     boost::accumulators::features<accumulators::tag::scheme_keys<ProcessingMode>>>;

            template<typename Mode>
            using part_verification_accumulator_set = boost::accumulators::accumulator_set<
                typename Mode::result_type, boost::accumulators::features<accumulators::tag::part_verify<Mode>>>;
        }    // namespace pubkey
    }        // namespace crypto3
}    // namespace nil

#endif    // CRYPTO3_BLOCK_CIPHER_STATE_HPP
